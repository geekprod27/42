/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfelsemb <nfelsemb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:10:14 by nfelsemb          #+#    #+#             */
/*   Updated: 2022/02/07 19:35:36 by nfelsemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(void)
{
	ft_printf("Error\n");
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
				err();
			tab2 = tab2->next;
		}
		flag = 1;
		tab = tab->next;
		tab2 = tab->next;
	}
}

void	indexeur(t_extrem *ex)
{
	int		i;
	t_tab	*un;
	t_tab	*deux;

	un = ex->deb;
	deux = un->next;
	while (un)
	{
		i = 0;
		while (deux)
		{
			if (deux->value < un->value)
				i++;
			deux = deux->next;
		}
		un->index = i;
		un = un->next;
		deux = ex->deb;
	}
}

int	main(int argc, char **argv)
{
	int			i;
	t_extrem	a;
	t_extrem	b;
	t_tab		*tab;
	t_tab		*av;

	if (argc <= 2)
		return (0);
	tab = malloc(sizeof(t_tab));
	a.deb = tab;
	a.end = tab;
	b.deb = NULL;
	if (!ft_isfulldigit(argv[1]) || ft_strlen(argv[1]) > 11 || !isint(argv[1]))
		err();
	tab->value = ft_atoi(argv[1]);
	i = 2;
	while (i <= argc - 1)
	{
		av = tab;
		tab = malloc(sizeof(t_tab));
		tab->prev = av;
		a.end = tab;
		av->next = tab;
		if (!ft_isfulldigit(argv[i]) || ft_strlen(argv[i]) > 11
			|| !isint(argv[i]))
			err();
		tab->value = ft_atoi(argv[i]);
		i++;
	}
	checkerr(a);
	indexeur(&a);
	printall(a, b);
	return (1);
}
