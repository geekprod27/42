/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:26:03 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/07 17:02:42 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortplusplus(t_extrem *a, t_extrem *b)
{
	while (lslen(a) > 3)
	{
		ft_printf("pb\n");
		push(a, b);
	}
	sortmoin(a);
}

t_mouv	unprev(t_extrem *a, t_mouv	temp, t_mouv best, t_point j)
{
	if (checktrie(a) && j.deux->index < j.un->index)
		best = savebest(temp.ra, temp.rb, best);
	else if (j.deux->index < j.un->index
		&& j.deux->index > j.un->prev->index)
		best = savebest(temp.ra, temp.rb, best);
	else if (j.un->index == getmin(*a) && j.un->index > j.deux->index)
		best = savebest(temp.ra, temp.rb, best);
	return (best);
}

t_mouv	getmou(t_extrem *a, t_mouv	temp, t_mouv best, t_point j)
{
	while (j.deux && temp.rb < best.ra + best.rb
		&& temp.ra < best.ra + best.rb && j.un)
	{
		if (j.un->prev)
			best = unprev(a, temp, best, j);
		else if ((checktrie(a) && j.deux->index < j.un->index)
			|| ((j.deux->index < j.un->index && j.deux->index > a->end->index)))
			best = savebest(temp.ra, temp.rb, best);
		if (j.deux->index == j.un->index - 1 && checktrie(a))
			best = savebest(temp.ra, temp.rb, best);
		else if (j.un->index == getmax(*a)
			&& j.un->index + 1 == j.deux->index)
				best = savebest(temp.ra + 1, temp.rb, best);
			j.deux = j.deux->next;
		temp.rb++;
	}
	return (best);
}

int	getrr(int len, t_tab *un)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < (len / 2) && len >= 6)
	{
		if (un->index < (len / 2))
			j++;
		i++;
		un = un->next;
	}
	return (i);
}

int	getrrr(int len, t_tab *un, t_extrem *a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < (len / 2) && len >= 6)
	{
		if (un->index < (len / 2))
			j++;
		i++;
		if (un->prev)
			un = un->prev;
		else
			un = a->end;
	}
	return (i);
}
