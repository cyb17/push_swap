/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bing <bing@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:42:08 by yachen            #+#    #+#             */
/*   Updated: 2023/07/04 22:20:11 by bing             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// verifie si les parametres passes sont des int
static int	check_argv(char **argv)
{
	int		i;
	int		j;
	long	nbr;

	i = 0;
	while (argv[i])
	{
		j = 0;
		nbr = ft_atoi(argv[i]);
		if (nbr == 0)
		{
			while (argv[i][j])
			{
				if (ft_isdigit(argv[i][j]) == 0)
					return (0);
				j++;
			}
		}
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

// verifie s'il n'y a pas de doublon
static int	check_double(char **argv)
{
	int i;
	int j;

	i = 0;
	while (argv[i + 1])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	parsing(int argc, char **argv)
{
	char	**new_argv;

	new_argv = NULL;
	if (argc == 1)
		exit(0);
	if(argc == 2)
		new_argv = argv_string(argv);
	else
		new_argv = argv + 1;
	if (check_argv(new_argv) == 0 || check_double(new_argv) == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
}

char	**argv_string(char **argv)
{
	char 	**tab;

	tab = ft_split(argv[1], ' ');
	if (!tab)
	{
		ft_printf("Error");
		exit(1);
	}
	return (tab);
}

t_list	*make_stack(int argc, char **argv)
{
	t_list	*list;
	char	**tab;
	int		i;

	list = NULL;
	tab = NULL;
	i = 0;
	if (argc == 2)
	{
		tab = argv_string(argv);
		while (tab[i])
		{
			ft_lstadd_back(&list, ft_lstnew(tab[i]));
			i++;
		}
		free_tab(tab);
		t_list	*test = list;
		while (test)
		{
			ft_printf("%s ", (char *)(test->content));
			test = test->next;
		}
		return (list);
	}
	while (--argc > 0)
		ft_lstadd_front(&list, ft_lstnew(argv[argc]));
	return (list);
}
