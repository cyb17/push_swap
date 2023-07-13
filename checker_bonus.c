/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:44:59 by yachen            #+#    #+#             */
/*   Updated: 2023/07/13 13:27:10 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*instruct;

	parsing(argc, argv);
	instruct = read_instruct(0);
	stack_b = NULL;
	check_instruct2(instruct);
	if (argc == 2)
		stack_a = make_string(argv);
	else
		stack_a = make_normal(argc, argv);
	check_stack_a2(instruct, stack_a);
	if (instruct == NULL && already_sorted(stack_a) == 1)
	{
		ft_printf("OK\n");
		free_stack(&stack_a);
		exit(0);
	}
	apply_inst(instruct, &stack_a, &stack_b);
	check_stack_a(stack_a, stack_b);
	check_stack_b(&stack_b);
	free_stack(&stack_a);
	free(instruct);
	return (0);
}
