/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 05:59:19 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/10 10:07:24 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_data
{
	int				nbphilo;
	int				tdie;
	int				teat;
	int				tsleep;
	int				nbrep;
	int				ismort;
	pthread_t		*th;
	pthread_mutex_t	speak;
}	t_data;

typedef struct s_philo
{
	int				nb;
	pthread_mutex_t	*lfour;
	pthread_mutex_t	*rfour;
	t_data			*data;
}	t_philo;

int		ft_atoi(const char *tab);
int		gettime(void);
int		getfour(t_philo phil, int *flag, int lasteat);
void	clearfour(t_philo phil, int flag);

#endif
