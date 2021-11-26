/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:04:22 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/11/24 17:52:46 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*sa;
	unsigned char		*sb;
	size_t				i;

	i = 0;
	sa = (unsigned char *) s1;
	sb = (unsigned char *) s2;
	while (sa[i] && sb[i] && i < n)
	{
		if (sa[i] != sb[i])
			return ((unsigned char)sa[i] - (unsigned char)sb[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)sa[i] - (unsigned char)sb[i]);
}
