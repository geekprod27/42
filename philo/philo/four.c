/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 08:23:02 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/16 16:38:47 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	getfour(t_philo *phil, int *flag, int lasteat)
{
	pthread_mutex_lock(phil->rfour);
	*flag = 1;
	if (!phil->data->ismort || gettime() - lasteat > phil->data->tdie)
		return (0);
	if (!phil->data->ismort || gettime() - lasteat > phil->data->tdie)
	{
		return (0);
	}
	printf("%d %d has taken a fork\n", gettime(), phil->nb);
	if (!phil->data->ismort || gettime() - lasteat > phil->data->tdie)
		return (0);
	pthread_mutex_lock(phil->lfour);
	*flag = 2;
	if (!phil->data->ismort)
	{
		return (0);
	}
	printf("%d %d has taken a fork\n", gettime(), phil->nb);
	return (1);
}

void	clearfour(t_philo *phil, int *flag)
{
	if (*flag >= 1)
		pthread_mutex_unlock(phil->rfour);
	if (*flag == 2)
		pthread_mutex_unlock(phil->lfour);
	flag = 0;
}

int	philsleep(t_philo	*phil, int lasteat)
{
	if (phil->data->ismort)
		printf("%d %d sleep\n", gettime(), phil->nb);
	if (gettime() + phil->data->tsleep > lasteat + phil->data->tdie)
	{
		while (gettime() < lasteat + phil->data->tdie && phil->data->ismort)
			usleep(1000);
		return (1);
	}
	else
		usleep(phil->data->tsleep * 1000);
	return (0);
}

int	phileat(t_philo	*phil, int lasteat)
{
	int	i;

	if (phil->data->ismort)
		printf("%d %d eating\n", gettime(), phil->nb);
	if (gettime() + phil->data->teat > lasteat + phil->data->tdie)
	{
		while (gettime() < lasteat + phil->data->tdie && phil->data->ismort)
			usleep(1000);
		return (1);
	}
	else
		usleep(phil->data->teat * 1000);
	i = 2;
	clearfour(phil, &i);
	return (0);
}
