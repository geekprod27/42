/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:13:35 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/02/08 18:12:59 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_extrem *s)
{
	int		val;
	int		indextemp;

	val = s->deb->value;
	indextemp = s->deb->index;
	s->deb->value = s->deb->next->value;
	s->deb->index = s->deb->next->index;
	s->deb->next->value = val;
	s->deb->next->index = indextemp;
}

void	ss(t_extrem *a, t_extrem *b)
{
	swap(a);
	swap(b);
}

void	push(t_extrem *a, t_extrem *b)
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

void	rotate(t_extrem *ex)
{
	t_tab	*un;
	t_tab	*deux;

	un = ex->deb;
	ex->deb = un->next;
	un->prev = ex->end;
	deux = ex->end;
	deux->next = un;
	ex->end = un;
}

void	revrot(t_extrem *ex)
{
	t_tab	*g;
	t_tab	*temp;

	g = ex->end->prev;
	temp = ex->end;
	ex->end->next = ex->deb;
	ex->end->prev->next = NULL;
	ex->deb->prev = ex->end;
	ex->end->prev = NULL;
	ex->end = g;
	ex->deb = temp;
}
