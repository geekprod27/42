/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:17:00 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/04 08:47:01 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mouv	getmouv(t_extrem *a, t_extrem *b)
{
	t_mouv	best;
	t_point	j;
	t_mouv	temp;

	temp.ra = 0;
	best.ra = 1000000;
	best.rb = 1000000;
	j.un = a->deb;
	while (j.un && temp.ra < best.ra + best.rb)
	{
		j.deux = b->deb;
		temp.rb = 0;
		best = getmou(a, temp, best, j);
		j.un = j.un->next;
		temp.ra++;
	}
	return (best);
}

void	setmouv2(t_extrem *a, t_extrem *b, t_mouv best)
{
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
	setmouv2(a, b, best);
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

void	pushmoit(int len, t_extrem *a, t_extrem *b, t_tab *un)
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
			ft_printf("rra\n");
			revrot(a);
			un = a->deb;
		}
	}
}
