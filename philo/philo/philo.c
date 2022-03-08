/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 05:48:25 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/08 08:04:04 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	gettime(void)
{
	struct timeval	b;
	static int		start;

	gettimeofday(&b, NULL);
	if (!start)
		start = (b.tv_sec * 1000) + (b.tv_usec / 1000);
	return ((b.tv_sec * 1000) + (b.tv_usec / 1000) - start);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	printf("%d\n", gettime());
	usleep(10000);
	printf("%d\n", gettime());
}
