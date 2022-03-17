/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 08:44:19 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/17 16:51:40 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	skipspace(char *sr)
{
	int	j;

	j = 0;
	while ((sr[j] >= 9 && sr[j] <= 13) || sr[j] == ' ')
		j++;
	return (j);
}

int	ft_atoi(const char *tab)
{
	int	res;
	int	i;
	int	neg;

	res = 0;
	i = 0;
	neg = 1;
	i = skipspace((char *)tab);
	if (tab[i] == '-' || tab[i] == '+')
	{
		if (tab[i] == '-')
			neg = -1;
		i++;
	}
	while (tab[i])
	{
		if (tab[i] >= 48 && tab[i] <= 57)
		{
			res = res * 10 + (tab[i] - 48);
		}
		else
			return (res * neg);
		i++;
	}
	return (res * neg);
}

void	four(int *flag, t_philo *phil)
{
	if (*flag == 0)
	{
		printf("%d %d has taken a fork\n", gettime(), phil->nb);
		pthread_mutex_unlock(&phil->rfour->mfour);
		*flag = 1;
	}
	else if (*flag == 1)
	{
		printf("%d %d has taken a fork\n", gettime(), phil->nb);
		pthread_mutex_unlock(&phil->lfour->mfour);
		*flag = 2;
	}
}
