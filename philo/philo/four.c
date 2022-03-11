/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 08:23:02 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/11 07:22:26 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	getfour(t_philo phil, int *flag, int lasteat)
{
	pthread_mutex_lock(phil.rfour);
	*flag = 1;
	if (!phil.data->ismort || gettime() - lasteat > phil.data->tdie)
		return (0);
	//pthread_mutex_lock(&phil.data->speak);
	if (!phil.data->ismort || gettime() - lasteat > phil.data->tdie)
	{
		//pthread_mutex_unlock(&phil.data->speak);
		return (0);
	}
	printf("%d %d has taken a fork\n", gettime(), phil.nb);
	//pthread_mutex_unlock(&phil.data->speak);
	if (!phil.data->ismort || gettime() - lasteat > phil.data->tdie)
		return (0);
	pthread_mutex_lock(phil.lfour);
	*flag = 2;
	if (!phil.data->ismort || gettime() - lasteat > phil.data->tdie)
		return (0);
	//pthread_mutex_lock(&phil.data->speak);
	if (!phil.data->ismort)
	{
		//pthread_mutex_unlock(&phil.data->speak);
		return (0);
	}
	printf("%d %d has taken a fork\n", gettime(), phil.nb);
	//pthread_mutex_unlock(&phil.data->speak);
	return (1);
}

void	clearfour(t_philo phil, int flag)
{
	if (flag >= 1)
		pthread_mutex_unlock(phil.rfour);
	if (flag == 2)
		pthread_mutex_unlock(phil.lfour);
}
