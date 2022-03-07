/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:28:27 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/07 17:17:42 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_extrem *a, t_extrem *b)
{
	revrot(a);
	revrot(b);
}

void	rr(t_extrem *a, t_extrem *b)
{
	rotate(a);
	rotate(b);
}

void	indexeur(t_extrem *ex)
{
	int		i;
	t_tab	*un;
	t_tab	*deux;

	un = ex->deb;
	deux = un->next;
	while (un)
	{
		i = 0;
		while (deux)
		{
			if (deux->value < un->value)
				i++;
			deux = deux->next;
		}
		un->index = i;
		un = un->next;
		deux = ex->deb;
	}
}

void	mainsuite(int argc, t_tab *tab, t_extrem *a, char **argv)
{
	int			i;
	t_tab		*av;

	i = 2;
	while (i <= argc - 1)
	{
		av = tab;
		tab = ft_calloc(sizeof(t_tab), 1);
		if (!tab)
			err(a);
		tab->prev = av;
		a->end = tab;
		av->next = tab;
		if (!ft_isfulldigit(argv[i]) || ft_strlen(argv[i]) > 11
			|| !isint(argv[i]))
			err(a);
		tab->value = ft_atoi(argv[i]);
		tab->index = -5;
		tab->next = NULL;
		i++;
	}
	mainsuite2(a, argc);
}

void	mainsuite2(t_extrem *a, int argc)
{
	t_extrem	b;

	b.deb = NULL;
	b.end = NULL;
	checkerr(*a);
	indexeur(a);
	if (checktrie(a))
	{
		freeall(a);
		exit(0);
	}
	if (argc - 1 <= 3)
		sortmoin(a);
	else
		sortplus(a, &b, lslen(a));
	freeall(a);
}
