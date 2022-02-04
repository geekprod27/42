/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:13:35 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/02/03 16:08:17 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_extrem s)
{
	t_tab	*un;
	t_tab	*deux;
	int		val;

	un = s.deb;
	deux = un->next;
	val = un->value;
	un->prev = deux;
	deux->prev = NULL;
	un->value = deux->value;
	deux->value = val;
}

void	ss(t_extrem a, t_extrem b)
{
	swap(a);
	swap(b);
}

void	pushb(t_extrem *a, t_extrem *b)
{
	t_tab	*un;
	t_tab	*deux;

	un = a->deb;
	if (!b->deb)
	{
		deux = malloc(sizeof(t_tab));
		b->deb = deux;
		b->end = deux;
		deux->value = un->value;
		a->deb = un->next;
		free(un);
	}
	else
	{
		deux = b->deb;
		a->deb = un->next;
		un->next = b->deb;
		b->deb = un;
	}
}