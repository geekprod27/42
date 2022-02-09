/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:46:36 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/02/09 14:01:06 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortmoin(t_extrem *a)
{
	t_tab	*un;
	t_tab	*deux;

	deux = ((un = a->deb), un->next);
	if (un->index > deux->index)
	{
		swap(a);
		ft_printf("sa\n");
	}
	deux = deux->next;
	if (deux)
	{
		if (un->index > deux->index)
		{
			revrot(a);
			ft_printf("rra\n");
		}
	}
}

int	lslen(t_extrem ex)
{
	int		i;
	t_tab	*un;

	i = 0;
	if (!ex.deb)
		return (0);
	un = ex.deb;
	while (un)
	{
		i++;
		un = un->next;
	}
	return (i);
}

void	sortplus(t_extrem *a, t_extrem *b, int len)
{
	t_tab	*un;
	int		i;

	un = a->deb;
	i = 0;
	if (len > 6)
	{
		while (i < len / 2)
		{
			if (un->index < len / 2)
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
	while (lslen(*a) > 3)
	{
		ft_printf("pb\n");
		push(a, b);
		un = a->deb;
	}
	sortmoin(a);
	while (b->deb->index < a->deb->index)
	{
		push(b, a);
		ft_printf("pa\n");
	}
}
