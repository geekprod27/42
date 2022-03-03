/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:17:00 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/03 12:50:34 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mouv	getmouv(t_extrem *a, t_extrem *b)
{
	t_mouv	best;
	t_tab	*un;
	t_tab	*deux;
	int		ra;
	int		rb;

	ra = 0;
	best.ra = 1000000;
	best.rb = 1000000;
	un = a->deb;
	while (un && ra < best.ra + best.rb)
	{
		deux = b->deb;
		rb = 0;
		while (deux && rb < best.ra + best.rb && ra < best.ra + best.rb)
		{
			if (un->prev)
			{
				if (checktrie(a) && deux->index < un->index)
				{
					if (ra + rb < best.ra + best.rb)
						best = savebest(ra, rb);
				}
				else if (deux->index < un->index
					&& deux->index > un->prev->index)
				{
					if (ra + rb < best.ra + best.rb)
						best = savebest(ra, rb);
				}
				else if (un->index == getmin(*a) && un->index > deux->index)
				{
					if (ra + rb < best.ra + best.rb)
						best = savebest(ra, rb);
				}
			}
			else if ((checktrie(a) && deux->index < un->index)
				|| ((deux->index < un->index && deux->index > a->end->index)))
			{
				if (ra + rb < best.ra + best.rb)
					best = savebest(ra, rb);
			}
			if (deux->index == un->index - 1 && checktrie(a))
			{
				if (ra + rb < best.ra + best.rb)
					best = savebest(ra, rb);
			}
			else if (un->index == getmax(*a) && un->index + 1 == deux->index)
			{
				ra++;
				if (ra + rb < best.ra + best.rb)
					best = savebest(ra, rb);
				ra--;
			}
			deux = deux->next;
			rb++;
		}
		un = un->next;
		ra++;
	}
	return (best);
}

void	setmouv(t_extrem *a, t_extrem *b, t_mouv best)
{
	while (best.rb > 0 && best.ra > 0)
	{
		best.rb--;
		best.ra--;
		rr(a, b);
		ft_printf("rr\n");
	}
	while (best.rb < 0 && best.ra < 0)
	{
		best.rb++;
		best.ra++;
		rrr(a, b);
		ft_printf("rrr\n");
	}
	while (best.rb > 0)
	{
		best.rb--;
		rotate(b);
		ft_printf("rb\n");
	}
	while (best.ra > 0)
	{
		best.ra--;
		rotate(a);
		ft_printf("ra\n");
	}
	while (best.rb < 0)
	{
		best.rb++;
		revrot(b);
		ft_printf("rrb\n");
	}
	while (best.ra < 0)
	{
		best.ra++;
		revrot(a);
		ft_printf("rra\n");
	}
	push(b, a);
	ft_printf("pa\n");
}

void	zerodeb(t_extrem *a)
{
	t_tab	*un;

	int (i) = 0;
	un = a->deb;
	while (un->index != 0)
	{
		un = un->next;
		i++;
	}
	if (i > lslen(*a) / 2)
	{
		while (a->deb->index != 0)
		{
			revrot(a);
			ft_printf("rra\n");
		}
	}
	else
	{
		while (a->deb->index != 0)
		{
			rotate(a);
			ft_printf("ra\n");
		}
	}
}
