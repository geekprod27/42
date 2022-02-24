/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:46:36 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/02/24 17:16:09 by nfelsemb         ###   ########.fr       */
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
		deux = ((un = a->deb->next), un->next);
		if (un->index > deux->index)
		{
			revrot(a);
			swap(a);
			ft_printf("rra\nsa\n");
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

int	checktrie(t_extrem *a)
{
	t_tab	*un;
	t_tab	*deux;

	un = a->deb;
	deux = un->next;
	while (un && deux)
	{
		if (un->index > deux->index)
			return (0);
		un = un->next;
		deux = deux->next;
	}
	return (1);
}

void	sortplus(t_extrem *a, t_extrem *b, int len)
{
	t_tab	*un;
	int		i;

	un = a->deb;
	i = 0;
	while (i < (len / 2))
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
	while (lslen(*a) > 3)
	{
		ft_printf("pb\n");
		push(a, b);
		un = a->deb;
	}
	sortmoin(a);
	printall(*a, *b);
	while (b->deb)
	{
		if (b->deb->index < a->deb->index && b->deb->index > a->end->index)
		{
			push(b, a);
			ft_printf("pa\n");
			printall(*a, *b);
		}
		else if (checktrie(a) && a->end->index < b->deb->index)
		{
			push(b, a);
			rotate(a);
			ft_printf("pa\nra\n");
			printall(*a, *b);
		}
		else if (b->deb->index == a->deb->index - 1)
		{
			push(b, a);
			ft_printf("pa\n");
			printall(*a, *b);
		}
		else
		{
			
			break ;
		}
	}
}
