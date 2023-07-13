/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:03:14 by yachen            #+#    #+#             */
/*   Updated: 2023/07/13 11:04:40 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	parsing(argc, argv);
	if (argc == 2)
		stack_a = make_string(argv);
	else
		stack_a = make_normal(argc, argv);
	if (already_sorted(stack_a) == 1 || lst_size(stack_a) == 1)
	{
		ft_printf("Stack already sorted or insufficient number in stack");
		free_stack(&stack_a);
		exit(0);
	}
	sort(&stack_a);
	free_stack(&stack_a);
	return (0);
}
