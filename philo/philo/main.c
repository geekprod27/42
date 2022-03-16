/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:52:51 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/16 16:52:21 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data			data;
	int				i;
	t_retfree		ret;

	gettime();
	i = 1;
	if (argc < 5 || argc > 6)
		return (printf("\033[91m/!\\ERREUR/!\\ : argument invalide !\n\033[0m"));
	ret = init(&data, argc, argv);
	if (ret.flag)
	{
		free(data.th);
		free(ret.four);
		free(ret.phil);
		return (printf("\033[91m/!\\ERREUR/!\\ : argument invalide !\n\033[0m"));
	}
	while (i < data.nbphilo)
	{
		pthread_join(data.th[i], NULL);
		i++;
	}
	free(data.th);
	free(ret.four);
	free(ret.phil);
	return (0);
}

int	checkdead(t_philo *phil, int *flag2)
{
	if (gettime() - phil->lasteat > phil->data->tdie && phil->data->ismort)
	{
		phil->data->ismort = 0;
		printf("%d %d died\n", gettime(), phil->nb);
		clearfour(phil, flag2);
		return (1);
	}
	return (0);
}

int	threadsui(t_philo *phil, int *flag2)
{
	clearfour(phil, flag2);
	if (phil->data->ismort == 0
		|| gettime() - phil->lasteat > phil->data->tdie)
		return (1);
	if (philsleep(phil, phil->lasteat))
		return (1);
	if (phil->data->ismort && gettime() - phil->lasteat < phil->data->tdie)
		printf("%d %d is thinking\n", gettime(), phil->nb);
	if (!phil->data->ismort)
		return (2);
	return (0);
}

t_philo	*initphil(void *arg, int *flag2, int *nbrep)
{
	t_philo	*phil;

	phil = (t_philo *) arg;
	phil->lasteat = gettime();
	flag2 = 0;
	nbrep = 0;
	flag2 = flag2;
	nbrep = nbrep;
	if (phil->nb % 2)
		usleep(phil->data->teat * 999);
	return (phil);
}
