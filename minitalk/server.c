/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:28:43 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/06 13:31:16 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include "libft/libft.h"

char	g_c;

char	*ft_strjoinchar(char const *s1, char const s2)
{
	int		i;
	int		len1;
	char	*dest;

	len1 = ft_strlen(s1);
	dest = malloc(sizeof(char) * (len1 + 2));
	if (!dest)
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	dest[len1] = s2;
	len1++;
	dest[len1] = '\0';
	return (dest);
}

static void	sigrec(int sig)
{
	static int		i;
	static char		*tmp;

	if (!tmp)
	{
		tmp = ft_calloc(1, sizeof(char));
		i = 8;
	}
	g_c = g_c << 1;
	if (sig == SIGUSR2)
		g_c++;
	if (i == 1)
	{
		if (g_c != '\0')
			tmp = ft_strjoinchar(tmp, g_c);
		else
		{
			ft_printf("%s\nEn attente de message ...\n", tmp);
			free(tmp);
			tmp = ft_calloc(1, sizeof(char));
		}
		i = 8;
	}
	else
		i--;
}

int	main(void)
{
	ft_printf("---------------------------\n-                         -\n");
	ft_printf("-   Pid serveur : %d    -\n", getpid());
	ft_printf("-                         -\n---------------------------\n");
	ft_printf("En attente de message ...\n");
	g_c = 0;
	signal(SIGUSR1, sigrec);
	signal(SIGUSR2, sigrec);
	while (1)
		pause();
}
