/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:17:27 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/28 12:28:10 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_tab	t_tab;

struct s_tab
{
	t_tab	*prev;
	int		value;
	t_tab	*next;
};

typedef struct s_extrem
{
	t_tab	*deb;
	t_tab	*end;
}	t_extrem;

#endif
