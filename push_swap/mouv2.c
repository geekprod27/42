/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:28:27 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/02/07 19:56:46 by nfelsemb         ###   ########.fr       */
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
