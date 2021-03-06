/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:51:24 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/12/03 11:43:51 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	exa(unsigned int nb)
{
	char const		*base;
	char			res[9];
	int				i;

	base = "0123456789abcdef";
	i = 8;
	if (nb == 0)
		return (ft_putstr("0"));
	while ((nb / 16) > 0 || i >= 8)
	{
		res[i] = base[(nb % 16)];
		nb /= 16;
		i--;
	}
	res[i] = base[(nb % 16)];
	return (print2(res, i));
}

int	mexa(unsigned int nb)
{
	char const		*base;
	char			res[9];
	int				i;
	int				j;

	j = 0;
	base = "0123456789ABCDEF";
	i = 8;
	if (nb == 0)
		return (ft_putstr("0"));
	while ((nb / 16) > 0 || i >= 8)
	{
		res[i] = base[(nb % 16)];
		nb /= 16;
		i--;
	}
	res[i] = base[(nb % 16)];
	return (print2(res, i));
}
