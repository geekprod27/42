/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:56:29 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/11/26 10:52:56 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	taille;
	int	i;
	int	j;

	i = ft_strlen(dst);
	j = 0;
	taille = i + ft_strlen((char *)src);
	if ()
	i++;
	while ((size_t)i < dstsize && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	return ((size_t) taille);
}
