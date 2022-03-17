/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:24:05 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/17 17:35:17 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eatdead(int *flag, t_philo *phil)
{
	usleep(1000);
	pthread_mutex_lock(&phil->data->dat);
	*flag = 1;
	if (!phil->data->ismort)
		return (1);
	pthread_mutex_unlock(&phil->data->dat);
	*flag = 0;
	return (0);
}

int	get1four(t_philo *phil, int *flag, int lasteat)
{
	pthread_mutex_lock(&phil->rfour->mfour);
	if (phil->rfour->four == 0)
	{
		phil->rfour->four = phil->nb;
		four(flag, phil);
		return (1);
	}
	pthread_mutex_unlock(&phil->rfour->mfour);
	pthread_mutex_lock(&phil->data->dat);
	if (gettime() - lasteat > phil->data->tdie || !phil->data->ismort)
		return (0);
	pthread_mutex_unlock(&phil->data->dat);
	usleep(1000);
	return (7);
}

int	get2four(t_philo *phil, int *flag, int lasteat)
{
	pthread_mutex_lock(&phil->lfour->mfour);
	if (phil->lfour->four == 0)
	{
		phil->lfour->four = phil->nb;
		four(flag, phil);
		return (1);
	}
	pthread_mutex_unlock(&phil->lfour->mfour);
	pthread_mutex_lock(&phil->data->dat);
	if (gettime() - lasteat > phil->data->tdie || !phil->data->ismort)
		return (0);
	pthread_mutex_unlock(&phil->data->dat);
	usleep(1000);
	return (7);
}
