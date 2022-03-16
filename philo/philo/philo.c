/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 05:48:25 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/16 16:53:02 by nfelsemb         ###   ########.fr       */
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

void	*thread(void *arg)
{
	t_philo		*phil;

	int flag2, (tmp), (nbrep);
	phil = initphil(arg, &flag2, &nbrep);
	while (phil->data->ismort)
	{
		if (checkdead(phil, &flag2) || !phil->data->ismort)
			break ;
		if (phil->data->ismort && getfour(phil, &flag2, phil->lasteat))
		{
			phil->lasteat = gettime();
			nbrep++;
			if (phileat(phil, phil->lasteat))
				continue ;
			flag2 = 0;
			if (phil->data->nbrep != 0 && phil->data->nbrep == nbrep)
				break ;
		}
		tmp = threadsui(phil, &flag2);
		if (tmp == 1)
			continue ;
		else if (tmp == 2)
			break ;
	}
	pthread_exit(arg);
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
		pthread_mutex_init(&ret->four[i], NULL);
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

	int (i) = -1;
	ret.phil = NULL;
	ret.four = NULL;
	data->nbphilo = ft_atoi(argv[1]);
	ret.four = malloc(sizeof(pthread_mutex_t) * (data->nbphilo));
	data->tdie = ft_atoi(argv[2]);
	data->teat = ft_atoi(argv[3]);
	data->tsleep = ft_atoi(argv[4]);
	data->th = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	data->ismort = 1;
	ret.phil = malloc(sizeof(t_philo) * data->nbphilo);
	while (i++ < data->nbphilo)
		ret.phil[i].data = data;
	i = 0;
	pthread_mutex_init(&data->speak, NULL);
	if (argc == 6)
		data->nbrep = ft_atoi(argv[5]);
	else
		data->nbrep = 0;
	return (*initsuite(data, &ret));
}
