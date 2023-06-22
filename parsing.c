/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:42:08 by yachen              #+#    #+#             */
/*   Updated: 2023/06/22 11:42:11 by yachen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_argv(int argc, char **argv)
{
	int		i;
	int		j;
	long	nbr;

	i = 1;
	while (i < argc)
	{
		j = 0;
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
	while (--i > 1)
		if (ft_strcmp(argv[i], argv[i - 1]) == 0)
			return (0);
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
	else if (check_argv(argc, argv) == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
}
