/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bing <bing@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:42:08 by yachen            #+#    #+#             */
/*   Updated: 2023/06/30 19:25:32 by bing             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// verifie si les parametres passes sont des int
static int	check_argv(int argc, char **argv)
{
	int		i;
	int		j;
	long	nbr;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		nbr = ft_atoi(argv[i] + 0);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

// verifie s'il n'y a pas de doublon
static int	check_double(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
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
	if (argc == 1)
		exit(0);
	else if(argc == 2)
	{
		ft_printf("Insufficient number !\n");
		exit(0);
	}
	else if (check_argv(argc, argv) == 0 || check_double(argc, argv) == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
}
