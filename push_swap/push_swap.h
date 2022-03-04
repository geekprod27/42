/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:17:27 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/04 09:08:41 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_tab	t_tab;

struct s_tab
{
	t_tab	*prev;
	int		value;
	int		index;
	t_tab	*next;
};

typedef struct s_extrem
{
	t_tab	*deb;
	t_tab	*end;
}	t_extrem;

typedef struct s_mouv
{
	int	ra;
	int	rb;
}	t_mouv;

typedef struct s_point
{
	t_tab	*un;
	t_tab	*deux;
}	t_point;

long int	ft_atol(const char *tab);
void		swap(t_extrem *s);
void		printall(t_extrem a, t_extrem b);
void		push(t_extrem *a, t_extrem *b);
void		ss(t_extrem *a, t_extrem *b);
void		rotate(t_extrem *ex);
void		revrot(t_extrem *ex);
void		rrr(t_extrem *a, t_extrem *b);
void		rr(t_extrem *a, t_extrem *b);
void		sortmoin(t_extrem *a);
void		sortplus(t_extrem *a, t_extrem *b, int len);
void		err(t_extrem tab);
int			checktrie(t_extrem *a);
int			getmin(t_extrem a);
int			getmax(t_extrem a);
t_mouv		getmouv(t_extrem *a, t_extrem *b);
void		setmouv(t_extrem *a, t_extrem *b, t_mouv best);
void		zerodeb(t_extrem *a);
int			lslen(t_extrem ex);
t_mouv		optibest(t_mouv best, t_extrem a, t_extrem b);
t_mouv		savebest(int ra, int rb, t_mouv best);
void		freeall(t_extrem tab);
void		mainsuite(int argc, t_tab *tab, t_extrem a, char **arg);
int			ft_isfulldigit(char *str);
int			isint(char *str);
void		checkerr(t_extrem ex);
void		indexeur(t_extrem *ex);
void		mainsuite2(t_extrem a, int argc);
void		sortplus2(t_extrem *a, t_extrem *b, int len);
void		sortplusplus(t_extrem *a, t_extrem *b);
t_mouv		unprev(t_extrem *a, t_mouv	temp, t_mouv best, t_point j);
t_mouv		getmou(t_extrem *a, t_mouv	temp, t_mouv best, t_point j);
int			getrr(int len, t_tab *un);
int			getrrr(int len, t_tab *un, t_extrem *a);
void		pushmoit(int len, t_extrem *a, t_extrem *b, t_tab *un);
void		pushmoiti(int len, t_extrem *a, t_extrem *b, t_tab *un);

#endif
