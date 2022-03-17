/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 05:59:19 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/17 17:35:29 by nfelsemb         ###   ########.fr       */
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
	pthread_mutex_t	dat;
}	t_data;

typedef struct s_four
{
	int				four;
	pthread_mutex_t	mfour;
}	t_four;

typedef struct s_philo
{
	int				nb;
	int				nbrep;
	t_four			*lfour;
	t_four			*rfour;
	int				lasteat;
	t_data			*data;
}	t_philo;

typedef struct s_retfree
{
	int				flag;
	t_philo			*phil;
	t_four			*four;
}	t_retfree;

int			ft_atoi(const char *tab);
int			gettime(void);
int			getfour(t_philo *phil, int *flag, int lasteat);
void		clearfour(t_philo *phil, int *flag);
int			philsleep(t_philo	*phil, int lasteat);
int			phileat(t_philo	*phil, int lasteat);
t_retfree	init(t_data *data, int argc, char **argv);
int			checkdead(t_philo *phil, int *flag2);
int			threadsui(t_philo *phil, int *flag2);
t_philo		*initphil(void *arg);
t_retfree	*initfour(t_retfree *ret, int i, t_data *data);
void		four(int *flag, t_philo *phil);
int			eatdead(int *flag, t_philo *phil);
int			get1four(t_philo *phil, int *flag, int lasteat);
int			get2four(t_philo *phil, int *flag, int lasteat);

#endif
