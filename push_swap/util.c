/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:16:42 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/02/24 15:39:25 by nfelsemb         ###   ########.fr       */
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
