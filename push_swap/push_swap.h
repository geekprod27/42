/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.frn>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:17:27 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/02/28 06:59:44 by nfelsemb         ###   ########.fr       */
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
void		err(void);
int			checktrie(t_extrem *a);
int			getmin(t_extrem a);
int			getmax(t_extrem a);
t_mouv		getmouv(t_extrem *a, t_extrem *b);
void		setmouv(t_extrem *a, t_extrem *b, t_mouv best);
void		zerodeb(t_extrem *a);
int			lslen(t_extrem ex);

#endif
