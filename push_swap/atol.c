/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:57:08 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/02/07 19:40:41 by nfelsemb         ###   ########.fr       */
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

void	printall(t_extrem a, t_extrem b)
{
	t_tab	*un;
	t_tab	*deux;

	un = a.deb;
	deux = b.deb;
	ft_printf("A    |    B\n");
	while ((un || deux))
	{
		if (un && deux)
			ft_printf("%d    |    %d\n", un->value, deux->value);
		else if (un && !deux)
			ft_printf("%d(%d)    |     \n", un->value, un->index);
		else if (!un && deux)
			ft_printf("     |    %d\n", deux->value);
		if (un != a.end && un)
			un = un->next;
		else
			un = NULL;
		if (deux != b.end && deux)
			deux = deux->next;
		else
			deux = NULL;
	}
}
