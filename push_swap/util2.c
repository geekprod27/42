/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:26:03 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/03 12:50:07 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortplusplus(t_extrem *a, t_extrem *b)
{
	while (lslen(*a) > 3)
	{
		ft_printf("pb\n");
		push(a, b);
	}
	sortmoin(a);
}
