/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:57:08 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/02/02 14:05:26 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	skipspaces(char *sr)
{
	int	j;

	j = 0;
	while ((sr[j] >= 9 && sr[j] <= 13) || sr[j] == ' ')
		j++;
	return (j);
}

// les opticiens
long int	ft_atol(const char *tab)
{
	long int	res;
	int			i;
	long int	neg;

	res = 0;
	i = 0;
	neg = 1;
	i = skipspaces((char *)tab);
	if (tab[i] == '-' || tab[i] == '+')
	{
		if (tab[i] == '-')
			neg = -1;
		i++;
	}
	while (tab[i])
	{
		if (ft_isdigit(tab[i]))
		{
			res = res * 10 + (tab[i] - 48);
		}
		else
			return (res * neg);
		i++;
	}
	return (res * neg);
}

