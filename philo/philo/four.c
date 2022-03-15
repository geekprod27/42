/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 08:23:02 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/15 16:59:15 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	getfour(t_philo *phil, int *flag, int lasteat)
{
	pthread_mutex_lock(phil->rfour);
	*flag = 1;
	if (!phil->data->ismort || gettime() - lasteat > phil->data->tdie)
		return (0);
	pthread_mutex_lock(&phil->data->speak);
	if (!phil->data->ismort || gettime() - lasteat > phil->data->tdie)
	{
		pthread_mutex_unlock(&phil->data->speak);
		return (0);
	}
	printf("%d %d has taken a fork\n", gettime(), phil->nb);
	pthread_mutex_unlock(&phil->data->speak);
	if (!phil->data->ismort || gettime() - lasteat > phil->data->tdie)
		return (0);
	pthread_mutex_lock(phil->lfour);
	*flag = 2;
	pthread_mutex_lock(&phil->data->speak);
	if (!phil->data->ismort)
	{
		pthread_mutex_unlock(&phil->data->speak);
		return (0);
	}
	printf("%d %d has taken a fork\n", gettime(), phil->nb);
	pthread_mutex_unlock(&phil->data->speak);
	return (1);
}

void	clearfour(t_philo *phil, int flag)
{
	if (flag >= 1)
		pthread_mutex_unlock(phil->rfour);
	if (flag == 2)
		pthread_mutex_unlock(phil->lfour);
}

int	philsleep(t_philo	*phil, int lasteat)
{
	int	time;

	time = 0;
	pthread_mutex_lock(&phil->data->speak);
	printf("%d %d sleep\n", gettime(), phil->nb);
	pthread_mutex_unlock(&phil->data->speak);
	while (time < phil->data->tsleep)
	{
		usleep(5000);
		time = time + 5;
		if (gettime() - lasteat > phil->data->tdie)
			return (1);
	}
	return (0);
}

int	phileat(t_philo	*phil, int lasteat)
{
	int	time;

	time = 0;
	pthread_mutex_lock(&phil->data->speak);
	printf("%d %d eating\n", gettime(), phil->nb);
	pthread_mutex_unlock(&phil->data->speak);
	while (time < phil->data->tsleep)
	{
		usleep(5000);
		time = time + 5;
		if (gettime() - lasteat > phil->data->tdie)
		{
			clearfour(phil, 2);
			return (1);
		}
	}
	clearfour(phil, 2);
	return (0);
}
