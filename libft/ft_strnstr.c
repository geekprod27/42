/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:18:02 by nfelsemb          #+#    #+#             */
/*   Updated: 2021/11/30 13:03:08 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((unsigned char)s2[j] == 0)
		return ((char *)s1);
	while (s1[i] && i < (int)n)
	{
		if (s1[i] == s2[j])
		{
			while (s1[i] == s2[j] && i < (int)n)
			{
				i++;
				j++;
			}
			if ((unsigned char)s2[j] == '\0')
				return ((char *)s1 + i - j);
		}
		i++;
		j = 0;
	}
	return (0);
}
