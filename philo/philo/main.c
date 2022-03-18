/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:52:51 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/18 14:11:30 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data			data;
	int				i;
	t_retfree		ret;

	gettime();
	i = 0;
	if (argc < 5 || argc > 6)
		return (printf("\033[91m/!\\ERREUR/!\\ : argument invalide !\n\033[0m"));
	ret = init(&data, argc, argv);
	if (ret.flag)
	{
		return (printf("\033[91m/!\\ERREUR/!\\ : argument invalide !\n\033[0m"));
	}
	while (i < data.nbphilo)
	{
		pthread_join(data.th[i], NULL);
		i++;
	}
	return (0);
}

int	checkdead(t_philo *phil, int *flag2)
{
	if (gettime() - phil->lasteat > phil->data->tdie && phil->data->ismort)
	{
		pthread_mutex_unlock(&phil->data->dat);
		pthread_mutex_lock(&phil->data->dat);
		phil->data->ismort = 0;
		printf("%d %d died\n", gettime(), phil->nb);
		clearfour(phil, flag2);
		pthread_mutex_unlock(&phil->data->dat);
		return (1);
	}
	pthread_mutex_unlock(&phil->data->dat);
	return (0);
}

int	threadsui(t_philo *phil, int *flag2)
{
	clearfour(phil, flag2);
	pthread_mutex_lock(&phil->data->dat);
	if (phil->data->ismort == 0
		|| gettime() - phil->lasteat > phil->data->tdie)
	{
		pthread_mutex_unlock(&phil->data->dat);
		return (1);
	}
	pthread_mutex_unlock(&phil->data->dat);
	if (philsleep(phil, phil->lasteat))
		return (1);
	pthread_mutex_lock(&phil->data->dat);
	if (!phil->data->ismort)
	{
		pthread_mutex_unlock(&phil->data->dat);
		return (2);
	}
	pthread_mutex_unlock(&phil->data->dat);
	if (gettime() - phil->lasteat < phil->data->tdie)
		printf("%d %d is thinking\n", gettime(), phil->nb);
	return (0);
}

t_philo	*initphil(void *arg)
{
	t_philo	*phil;

	phil = (t_philo *) arg;
	phil->lasteat = gettime();
	phil->nbrep = 0;
	if (phil->nb % 2)
		usleep(phil->data->teat * 1000);
	return (phil);
}
