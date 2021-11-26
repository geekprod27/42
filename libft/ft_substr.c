/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:17:34 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/11/26 14:35:44 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;

	i = 0;
	if (len > ft_strlen((char *)s))
		len = ft_strlen((char *)s) - start;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest || !s)
		return (0);
	if (start > ft_strlen((char *)s))
		dest[0] = 0;
	else
		ft_strlcpy(dest, s + start, len + 1);
	return (dest);
}
