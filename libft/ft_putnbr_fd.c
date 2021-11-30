/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:06:25 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/11/30 12:35:01 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	longu2(long int num)
{
	int	lon;

	lon = 0;
	if (num < 0)
	{
		num = -num;
		lon++;
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		lon++;
	}
	return (lon);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	na[13];

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	i = longu2(n) - 1;
	if (n < 0)
	{
		na[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		na[i--] = (n % 10) + 48;
		n = n / 10;
	}
	ft_putstr_fd(na, fd);
}
