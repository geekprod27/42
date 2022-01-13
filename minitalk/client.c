/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:28:41 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/06 15:03:35 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <sys/types.h>
#include <signal.h>

void	checkerr(int err)
{
	if (err == -1)
	{
		ft_printf("Erreur de transmition !");
		exit(2);
	}
}

void	ft_send(char *str, int pid)
{
	int	i;
	int	j;
	int	b;
	int	ret;

	j = 0;
	b = 1;
	while (b)
	{
		if (str[j] == '\0')
			b = 0;
		i = 7;
		while (i != -1)
		{
			if ((str[j] >> i) % 2)
				ret = kill(pid, SIGUSR2);
			else
				ret = kill(pid, SIGUSR1);
			i--;
			checkerr(ret);
			usleep(100);
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Erreur d'argument\n");
		exit(2);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Le pid ne peut pas etre de 0 ou inferieur !\n");
		exit(3);
	}
	ft_printf("Envoie du message sur le pid : %d\n", pid);
	ft_send(argv[2], pid);
	ft_printf("Message envoye !\n");
}
