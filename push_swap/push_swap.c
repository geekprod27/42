/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:10:14 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/28 12:37:48 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_extrem	ex;
	t_tab		*tab;
	t_tab		*av;

	if (argc <= 2)
		return (0);
	tab = malloc(sizeof(t_tab));
	ex.deb = tab;
	ex.end = tab;
	tab->value = ft_atoi(argv[1]);
	i = 2;
	while (i <= argc)
	{
		av = tab;
		tab = malloc(sizeof(t_tab));
		tab->prev = av;
		av->next = tab;
		tab->value = ft_atoi(argv[i]);
		i++;
	}
	(void) ex;
	return (1);
}
