/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:28:43 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/04 16:00:30 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>

typedef void	(*t_sighandler)(int);

static void	sigrec(int sig)
{
	ft_printf("ok\n");
	(void) sig;
}

int	main(void)
{
	ft_printf("---------------------------\n-                         -\n");
	ft_printf("-   Pid serveur : %d   -\n", getpid());
	ft_printf("-                         -\n---------------------------\n");
	sleep(5);
	signal(SIGUSR1, sigrec);
	while (1)
	{
		pause();
	}
}
