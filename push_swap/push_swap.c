/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:10:14 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/03/21 15:41:20 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(t_extrem *tab)
{
	ft_printf("Error\n");
	if (tab)
		freeall(tab);
	exit(1);
}

int	ft_isfulldigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	isint(char *str)
{
	if (ft_atol(str) < -2147483648 || ft_atol(str) > 2147483647)
		return (0);
	return (1);
}

void	checkerr(t_extrem ex)
{
	t_tab	*tab;
	t_tab	*tab2;
	int		flag;

	flag = 1;
	tab = ex.deb;
	tab2 = tab->next;
	while (tab != ex.end)
	{
		while (flag)
		{
			if (tab2 == ex.end)
				flag = 0;
			if (tab->value == tab2->value)
				err(&ex);
			tab2 = tab2->next;
		}
		flag = 1;
		tab = tab->next;
		tab2 = tab->next;
	}
}

int	main(int argc, char **argv)
{
	t_extrem	a;
	t_tab		*tab;

	tab = ft_calloc(sizeof(t_tab), 1);
	if (!tab)
		return (0);
	a.deb = tab;
	a.end = tab;
	if (argc == 1)
	{
		free(tab);
		return (0);
	}
	if (!ft_isfulldigit(argv[1]) || ft_strlen(argv[1]) > 11 || !isint(argv[1]))
		err(&a);
	if (argc <= 2)
	{
		free(tab);
		return (0);
	}
	tab->value = ft_atoi(argv[1]);
	tab->index = -5;
	tab->next = NULL;
	mainsuite(argc, tab, &a, argv);
	return (1);
}
