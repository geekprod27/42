/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:10:14 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/01/27 21:41:44 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_extrem	ex;
	t_tab		*tab;

	if (argc == 1)
		return (0);
	if (!t_extrem.deb)
		return (0);
	tab = malloc(sizeof(t_tab));
	tab->value = ft_atoi(argv[1]);
	i = 1;
	while (i <= argc)
	{
		tab = malloc(sizeof(t_tab));
		
	}
	return (1);
}
