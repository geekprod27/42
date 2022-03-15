/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 05:59:19 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/15 16:54:04 by nfelsemb         ###   ########.fr       */
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

typedef struct s_retfree
{
	int				flag;
	t_philo			*phil;
	pthread_mutex_t	*four;
}	t_retfree;

int			ft_atoi(const char *tab);
int			gettime(void);
int			getfour(t_philo *phil, int *flag, int lasteat);
void		clearfour(t_philo *phil, int flag);
int			philsleep(t_philo	*phil, int lasteat);
int			phileat(t_philo	*phil, int lasteat);
t_retfree	init(t_data *data, int argc, char **argv);

#endif
