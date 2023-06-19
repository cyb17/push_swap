/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:49:06 by yachen            #+#    #+#             */
/*   Updated: 2023/06/19 13:57:52 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parsing(char **argv)
{
	int		i;
	int		j;
	long	nbr;

	i = 0;
	j = 0;
	while (argv + i)
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		i++;
	}
	while (--i)
		if (ft_strcmp(argv[i], argv[i - 1]) == 0)
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (ft_parsing(argv) == 0)
		write(2, "Error", 5);
	return (0);
}
