/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:46:36 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/04 08:51:37 by nfelsemb         ###   ########.fr       */
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
	sortplus2(a, b, len);
	while (b->deb)
	{
		a->deb->prev = NULL;
		if (checktrie(a) && a->end->index < b->deb->index)
		{
			push(b, a);
			ft_printf("pa\n");
		}
		else if (b->deb->index == a->deb->index - 1 && checktrie(a))
		{
			push(b, a);
			ft_printf("pa\n");
		}
		else if (checktrie(a) && a->deb->index > b->deb->index)
		{
			push(b, a);
			ft_printf("pa\n");
		}
		else
			setmouv(a, b, optibest(getmouv(a, b), *a, *b));
	}
	zerodeb(a);
}

void	sortplus2(t_extrem *a, t_extrem *b, int len)
{
	t_tab	*un;

	un = a->deb;
	if (getrr(len, un) > getrrr(len, un, a))
		pushmoiti(len, a, b, un);
	else
		pushmoit(len, a, b, un);
	sortplusplus(a, b);
}
