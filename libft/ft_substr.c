/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:17:34 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/11/26 12:29:50 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * len + 1);
	while (s[start] && (size_t)i < len)
	{
		dest[i++] = s[start++];
	}
	dest[i] = '\0';
	return (dest);
}