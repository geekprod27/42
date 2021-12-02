/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:51:24 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/12/02 14:54:27 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	exa(unsigned int nb)
{
	char const		*base;
	char			res[9];
	int				i;
	int				j;

	j = 0;
	base = "0123456789abcdef";
	i = 8;
	while ((nb / 16) > 0 || i >= 8)
	{
		res[i] = base[(nb % 16)];
		nb /= 16;
		i--;
	}
	res[i] = base[(nb % 16)];
	while (res[i] == '0')
		i++;
	while (i < 9 && res[i])
	{
		ft_putchar (res[i++]);
		j++;
	}
	return (j);
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
	while ((nb / 16) > 0 || i >= 8)
	{
		res[i] = base[(nb % 16)];
		nb /= 16;
		i--;
	}
	res[i] = base[(nb % 16)];
	while (res[i] == '0')
		i++;
	while (i < 9 && res[i])
	{
		ft_putchar (res[i++]);
		j++;
	}
	return (j);
}