/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:47:52 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/11/23 16:47:54 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*d;

	d = s;
	while (n > 0)
	{
		*d = 0;
		d++;
		n--;
	}
	return (s);
}