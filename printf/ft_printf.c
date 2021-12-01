/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:15:01 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/12/01 07:22:53 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	ap;
	int 	cc;

	va_start(ap, s);
	i = 0;
	cc = 0;
	while (s[i])
	{
		while (s[i] != '%' && s[i])
		{
			ft_putchar(s[i]);
			i++;
			cc++;
		}
		if (s[i] == '%' && s[i])
			i++;
		if (s[i] == '%' && s[i])
		{
			ft_putchar('%');
			cc++;
		}
		else if (s[i] == 's' && s[i])
			cc = cc + ft_putstr(va_arg (ap, char *));
		else if (s[i] == 'd' && s[i])
			cc = cc + ft_putnbr(va_arg (ap, int), 0);
		else if (s[i] == 'c' && s[i])
		{
			ft_putchar(va_arg (ap, unsigned int));
			cc++;
		}
		i++;
	}
	va_end(ap);
	return (cc);
}
