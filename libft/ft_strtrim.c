/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:06:22 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/11/29 16:12:55 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isd(char c, char const *d)
{
	int	i;

	i = 0;
	while (d[i])
	{
		if (d[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!dest)
		return (0);
	while (!isd(s1[i], set))
		i++;
	if (!s1[i])
		return ("\0");
	while (s1[i])
	{
		dest[j++] = s1[i++];
	}
	dest[j] = '\0';
	j--;
	while (!isd(dest[j], set))
	{
		dest[j] = '\0';
		j--;
	}
	return (dest);
}
