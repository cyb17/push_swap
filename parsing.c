/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:10:45 by yachen            #+#    #+#             */
/*   Updated: 2023/07/18 13:41:29 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check(const char *str)
{
	int	i;

	i = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}	
	return (1);
}

static long	ft_atoi_long(const char *str)
{
	int			i;
	long		nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (ft_check(str) == 0)
		return (0);
	while (str[i] && (str[i] == ' ' || ((str[i] > 8 && str[i] < 14))))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

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
		nbr = ft_atoi_long(argv[i]);
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
	int	i;
	int	j;

	i = 0;
	while (argv[i + 1])
	{
		j = i + 1;
		while (argv[j])
		{
			if (stringcmp(argv[i], argv[j]) == 0)
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
	if (argc == 1 || argv[1][0] == '\0')
		exit(0);
	if (argc == 2)
	{
		new_argv = ft_split(argv[1], ' ');
		if (check_argv(new_argv) == 0 || check_double(new_argv) == 0)
		{
			free_tab(new_argv);
			ft_error();
		}
		free_tab(new_argv);
	}
	else
	{
		new_argv = argv + 1;
		if (check_argv(new_argv) == 0 || check_double(new_argv) == 0)
			ft_error();
	}
}
