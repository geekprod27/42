/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:17:00 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/02/25 15:36:46 by nfelsemb         ###   ########.fr       */
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

	ra = 1;
	best.ra = 1000000;
	best.rb = 1000000;
	un = a->deb;
	while (un)
	{
		deux = b->deb;
		rb = 0;
		while (deux)
		{
			if (un->next)
			{
				if ((deux->index > un->index && deux->index < un->next->index
						&& checktrie(a)) || (deux->index == un->index - 1
						&& !checktrie(a)))
				{
					if (deux->index == un->index - 1 && !checktrie(a))
						ra--;
					if (ra + rb < best.ra + best.rb)
					{
						best.ra = ra;
						best.rb = rb;
					}
				}
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
	while (best.rb && best.ra)
	{
		best.rb--;
		best.ra--;
		rr(a, b);
		ft_printf("rr\n");
	}
	while (best.rb)
	{
		best.rb--;
		rotate(b);
		ft_printf("rb\n");
	}
	while (best.ra)
	{
		best.ra--;
		rotate(a);
		ft_printf("ra\n");
		printall(*a, *b);
	}
	push(b, a);
	ft_printf("pa\n");
}
