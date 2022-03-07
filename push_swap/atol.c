/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:57:08 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/07 17:18:06 by nfelsemb         ###   ########.fr       */
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

long int	les_opticiens(const char *tab, int i, int neg)
{
	long int	res;

	res = 0;
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

long int	ft_atol(const char *tab)
{
	int			i;
	long int	neg;
	t_extrem	*a;

	i = 0;
	neg = 1;
	a = NULL;
	i = skipspaces((char *)tab);
	if (tab[i] == '-' || tab[i] == '+')
	{
		if (tab[i] == '-')
			neg = -1;
		i++;
		if (!tab[i])
			err(a);
	}
	return (les_opticiens(tab, i, neg));
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
			ft_printf("%d(%d)    |    %d(%d)\n", un->value, un->index,
				deux->value, deux->index);
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

void	pushmoiti(int len, t_extrem *a, t_extrem *b, t_tab *un)
{
	int	i;

	i = 0;
	while (i < (len / 2) && len >= 6)
	{
		if (un->index < (len / 2))
		{
			ft_printf("pb\n");
			push(a, b);
			un = a->deb;
			i++;
		}
		else
		{
			ft_printf("ra\n");
			rotate(a);
			un = a->deb;
		}
	}
}
