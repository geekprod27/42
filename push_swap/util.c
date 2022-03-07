/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:16:42 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/07 14:10:05 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getmin(t_extrem a)
{
	t_tab	*un;
	int		min;

	un = a.deb;
	min = a.deb->index;
	un = un->next;
	while (un)
	{
		if (un->index < min)
			min = un->index;
		un = un->next;
	}
	return (min);
}

int	getmax(t_extrem a)
{
	t_tab	*un;
	int		max;

	un = a.deb;
	max = a.deb->index;
	un = un->next;
	while (un)
	{
		if (un->index > max)
			max = un->index;
		un = un->next;
	}
	return (max);
}

t_mouv	optibest(t_mouv best, t_extrem *a, t_extrem *b)
{
	if (best.ra < 0)
		best.ra = 0;
	if (best.rb < 0)
		best.rb = 0;
	if (best.ra > lslen(a) / 2)
		best.ra = (lslen(a) - best.ra) * -1;
	if (best.rb > lslen(b) / 2)
		best.rb = (lslen(b) - best.rb) * -1;
	return (best);
}

t_mouv	savebest(int ra, int rb, t_mouv best)
{
	if (ra + rb < best.ra + best.rb)
	{
		best.ra = ra;
		best.rb = rb;
	}
	return (best);
}

void	freeall(t_extrem *tab)
{
	t_tab	*un;
	t_tab	*deux;

	un = tab->deb;
	deux = un->next;
	while (un)
	{
		free(un);
		un = deux;
		if (un)
			deux = un->next;
	}
}
