/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:52:51 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/15 16:53:27 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data			data;
	int				i;
	t_retfree		ret;

	gettime();
	i = 1;
	if (argc < 5 || argc > 6)
		return (printf("\033[91m/!\\ERREUR/!\\ : argument invalide !\n\033[0m"));
	ret = init(&data, argc, argv);
	if (ret.flag)
	{
		free(data.th);
		free(ret.four);
		free(ret.phil);
		return (printf("\033[91m/!\\ERREUR/!\\ : argument invalide !\n\033[0m"));
	}
	while (i < data.nbphilo)
	{
		pthread_join(data.th[i], NULL);
		i++;
	}
	free(data.th);
	free(ret.four);
	free(ret.phil);
	return (0);
}
