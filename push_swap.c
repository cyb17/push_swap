/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:49:06 by yachen            #+#    #+#             */
/*   Updated: 2023/06/21 14:46:29 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parsing(int argc, char **argv)
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	int		value;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		ft_printf("Insufficient number!");
	else if (ft_parsing(argc, argv) == 0)
		write(2, "Error\n", 6);
	else
	{
		stack_a = ft_make_stack(argc, argv);
		while (stack_a)
		{
			value = *((int *)(stack_a->content));
			ft_printf("%d", value);
			stack_a = stack_a->next;
		}
	}
	return (0);
}
