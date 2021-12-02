/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:06:06 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/12/02 13:07:52 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printpoint(void *s)
{
	unsigned long	adr;
	char const		*base;
	char			res[9];
	int				i;
	int				j;

	j = 0;
	adr = (unsigned long) s;
	base = "0123456789abcdef";
	i = 8;
	while ((adr / 16) > 0 || i >= 8)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	while (res[i] == '0')
		i++;
	while (i < 9 && res[i])
	{
		ft_putchar (res[i++]);
		j++;
	}
	return (j);
}
