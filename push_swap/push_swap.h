/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:17:27 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/02/07 19:01:05 by nfelsemb         ###   ########.fr       */
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

long int	ft_atol(const char *tab);
void		swap(t_extrem s);
void		printall(t_extrem a, t_extrem b);
void		pushb(t_extrem *a, t_extrem *b);
void		ss(t_extrem a, t_extrem b);
void		rotate(t_extrem *ex);
void		revrot(t_extrem *ex);
void		rrr(t_extrem *a, t_extrem *b);
void		rr(t_extrem *a, t_extrem *b);

#endif
