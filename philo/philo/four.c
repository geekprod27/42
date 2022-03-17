/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 08:23:02 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/17 17:36:36 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	getfour(t_philo *phil, int *flag, int lasteat)
{
	int	ret;

	while (1)
	{
		ret = get1four(phil, flag, lasteat);
		if (ret == 1)
			break ;
		else if (ret == 0)
			return (0);
	}
	while (1)
	{
		ret = get2four(phil, flag, lasteat);
		if (ret == 1)
			break ;
		else if (ret == 0)
			return (0);
	}
	return (1);
}

void	clearfour(t_philo *phil, int *flag)
{
	if (*flag >= 1)
	{
		pthread_mutex_lock(&phil->rfour->mfour);
		phil->rfour->four = 0;
		pthread_mutex_unlock(&phil->rfour->mfour);
	}
	if (*flag == 2)
	{
		pthread_mutex_lock(&phil->lfour->mfour);
		phil->lfour->four = 0;
		pthread_mutex_unlock(&phil->lfour->mfour);
	}
	*flag = 0;
}

int	philsleep(t_philo	*phil, int lasteat)
{
	int (flag) = 0;
	pthread_mutex_lock(&phil->data->dat);
	if (phil->data->ismort)
		printf("%d %d sleep\n", gettime(), phil->nb);
	pthread_mutex_unlock(&phil->data->dat);
	if (gettime() + phil->data->tsleep > lasteat + phil->data->tdie)
	{
		while (gettime() < lasteat + phil->data->tdie)
		{
			usleep(1000);
			pthread_mutex_lock(&phil->data->dat);
			flag = 1;
			if (!phil->data->ismort)
				break ;
			pthread_mutex_unlock(&phil->data->dat);
			flag = 0;
		}
		if (flag)
			pthread_mutex_unlock(&phil->data->dat);
		return (1);
	}
	else
		usleep(phil->data->tsleep * 1000);
	return (0);
}

int	phileat(t_philo	*phil, int lasteat)
{
	int i, (flag) = 0;
	pthread_mutex_lock(&phil->data->dat);
	if (phil->data->ismort)
		printf("%d %d eating\n", gettime(), phil->nb);
	pthread_mutex_unlock(&phil->data->dat);
	if (gettime() + phil->data->teat > lasteat + phil->data->tdie)
	{
		while (gettime() < lasteat + phil->data->tdie)
		{
			if (eatdead(&flag, phil))
				break ;
		}
		if (flag)
			pthread_mutex_unlock(&phil->data->dat);
		return (1);
	}
	else
		usleep(phil->data->teat * 1000);
	i = 2;
	clearfour(phil, &i);
	return (0);
}

t_retfree	*initfour(t_retfree *ret, int i, t_data *data)
{
	ret->phil[i].nb = i + 1;
	if (i == data->nbphilo)
		ret->phil[i].rfour = &ret->four[0];
	else if (data->nbphilo != 1)
		ret->phil[i].rfour = &ret->four[i];
	else
		ret->phil[i].rfour = &ret->four[i];
	if (i != 0)
		ret->phil[i].lfour = &ret->four[i - 1];
	else
		ret->phil[i].lfour = &ret->four[data->nbphilo - 1];
	return (ret);
}
