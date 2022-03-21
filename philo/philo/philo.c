/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 05:48:25 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/21 16:41:08 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	gettime(void)
{
	struct timeval	b;
	static int		start;

	gettimeofday(&b, NULL);
	if (!start)
		start = (b.tv_sec * 1000) + (b.tv_usec / 1000);
	return ((b.tv_sec * 1000) + (b.tv_usec / 1000) - start);
}

void	incre(t_philo *phil)
{
	phil->lasteat = gettime();
	phil->nbrep++;
}

void	*thread(void *arg)
{
	int (tmp), (flag2) = 0;
	t_philo *(phil) = initphil(arg);
	while (1)
	{
		pthread_mutex_lock(&phil->data->dat);
		if (checkdead(phil, &flag2) || !phil->data->ismort)
			break ;
		if (getfour(phil, &flag2, phil->lasteat))
		{
			incre(phil);
			if (phileat(phil, phil->lasteat))
				continue ;
			flag2 = 0;
			if (phil->data->nbrep != 0 && phil->data->nbrep == phil->nbrep)
				break ;
		}
		else
			pthread_mutex_unlock(&phil->data->dat);
		tmp = threadsui(phil, &flag2);
		if (tmp == 1)
			continue ;
		else if (tmp == 2)
			break ;
	}
	pthread_exit(arg);
}

t_retfree	*initsuite(t_data *data, t_retfree *ret)
{
	int (i) = 0;
	if (data->nbphilo <= 0 || data->tdie <= 0 || data->tdie <= 0
		|| data->tdie <= 0 || data->tdie <= 0)
	{
		ret->flag = 1;
		return (ret);
	}
	while (i < data->nbphilo)
	{
		pthread_mutex_init(&ret->four[i].mfour, NULL);
		ret->four[i].four = 0;
		i++;
	}
	i = 0;
	ret->phil[i].nb = 0;
	while (i < data->nbphilo)
	{
		ret = initfour(ret, i, data);
		pthread_create(&data->th[i], NULL, thread, &ret->phil[i]);
		i++;
	}
	ret->flag = 0;
	return (ret);
}

t_retfree	init(t_data *data, int argc, char **argv)
{
	t_retfree		ret;

	int (i) = 0;
	data->nbphilo = ft_atoi(argv[1]);
	inidata(data, argv);
	ret.four = malloc(sizeof(t_four) * (data->nbphilo));
	ret.phil = malloc(sizeof(t_philo) * data->nbphilo);
	if (!ret.phil || !ret.four)
	{
		ret.flag = 1;
		return (ret);
	}
	while (i < data->nbphilo)
	{
		ret.phil[i].data = data;
		i++;
	}
	i = 0;
	pthread_mutex_init(&data->dat, NULL);
	if (argc == 6)
		data->nbrep = ft_atoi(argv[5]);
	else
		data->nbrep = 0;
	return (*initsuite(data, &ret));
}
