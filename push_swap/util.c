/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:16:42 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/02 17:19:38 by nfelsemb         ###   ########.fr       */
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

t_mouv	optibest(t_mouv best, t_extrem a, t_extrem b)
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
