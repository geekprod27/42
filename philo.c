/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 05:48:25 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/10 10:12:25 by nfelsemb         ###   ########.fr       */
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
	t_philo		phil;
	int			lasteat;
	int			flag;
	int			flag2;

	phil = *(t_philo *) arg;
	lasteat = gettime();
	flag2 = 0;
	while (phil.data->ismort)
	{
		pthread_mutex_lock(&phil.data->speak);
		if (gettime() - lasteat > phil.data->tdie && phil.data->ismort)
		{
			phil.data->ismort = 0;
			printf("%d %d died\n", gettime(), phil.nb);
			pthread_mutex_unlock(&phil.data->speak);
			if (flag2)
				clearfour(phil, flag2);
			break ;
		}
		if (!phil.data->ismort)
			break ;
		pthread_mutex_unlock(&phil.data->speak);
		if (getfour(phil, &flag2, lasteat))
		{
			if (phil.data->ismort)
			{
				pthread_mutex_lock(&phil.data->speak);
				printf("%d %d eating\n", gettime(), phil.nb);
				pthread_mutex_unlock(&phil.data->speak);
				lasteat = gettime();
				usleep(phil.data->teat * 1000);
				clearfour(phil, 2);
				flag2 = 0;
			}
		}
		else
		{
			clearfour(phil, flag2);
			flag2 = 0;
		}
		if (!phil.data->ismort)
			break ;
		pthread_mutex_lock(&phil.data->speak);
		flag = 1;
		if (gettime() - lasteat < phil.data->tdie && phil.data->ismort)
		{
			printf("%d %d sleep\n", gettime(), phil.nb);
			pthread_mutex_unlock(&phil.data->speak);
			flag = 0;
			usleep(phil.data->tsleep * 1000);
		}
		if (flag)
			pthread_mutex_unlock(&phil.data->speak);
		if (!phil.data->ismort)
			break ;
		pthread_mutex_lock(&phil.data->speak);
		if (phil.data->ismort && gettime() - lasteat < phil.data->tdie)
			printf("%d %d is thinking\n", gettime(), phil.nb);
		pthread_mutex_unlock(&phil.data->speak);
		if (!phil.data->ismort)
			break ;
	}
	pthread_mutex_unlock(&phil.data->speak);
	pthread_exit(arg);
}

pthread_mutex_t	*init(t_data *data, int argc, char **argv)
{
	int				i;
	t_philo			phil;
	pthread_mutex_t	*four;

	i = 1;
	data->nbphilo = ft_atoi(argv[1]);
	four = malloc(sizeof(pthread_mutex_t) * (data->nbphilo + 1));
	data->tdie = ft_atoi(argv[2]);
	data->teat = ft_atoi(argv[3]);
	data->tsleep = ft_atoi(argv[4]);
	data->th = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	data->ismort = 1;
	phil.data = data;
	pthread_mutex_init(&data->speak, NULL);
	if (argc == 6)
		data->nbrep = ft_atoi(argv[5]);
	else
		data->nbrep = 0;
	if (data->nbphilo == 0 || data->tdie == 0 || data->tdie == 0
		|| data->tdie == 0 || data->tdie == 0)
		return (0);
	while (i <= data->nbphilo)
	{
		pthread_mutex_init(&four[i], NULL);
		i++;
	}
	i = 1;
	while (i <= data->nbphilo)
	{
		phil.nb = i;
		if (i == data->nbphilo)
			phil.rfour = &four[1];
		else
			phil.rfour = &four[i + 1];
		phil.lfour = &four[i];
		usleep(55);
		pthread_create(&data->th[i], NULL, thread, &phil);
		usleep(50);
		i++;
	}
	return (four);
}

int	main(int argc, char **argv)
{
	t_data			data;
	int				i;
	pthread_mutex_t	*four;

	gettime();
	i = 0;
	if (argc < 5 || argc > 6)
		return (printf("\033[91m/!\\ERREUR/!\\ : argument invalide !\n\033[0m"));
	four = init(&data, argc, argv);
	if (!four)
		return (printf("\033[91m/!\\ERREUR/!\\ : argument invalide !\n\033[0m"));
	while (i + 1 <= data.nbphilo)
	{
		pthread_join(data.th[i + 1], NULL);
		i++;
	}
	free(data.th);
	free(four);
	return (0);
}
