/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bing <bing@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:49:06 by yachen            #+#    #+#             */
/*   Updated: 2023/07/03 16:46:30 by bing             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	parsing(argc, argv);
	stack_a = make_stack(argc, argv);
	if (already_sorted(stack_a) == 1)
	{
		ft_printf("The stack is already sorted :)");
		free_stack(&stack_a);
		exit(0);
	}
	if (argc == 3)
		sa(&stack_a);
	else
		sort(&stack_a);
	t_list	*test = stack_a;
	while (test)
	{
		ft_printf("%s ", (char *)(test->content));
		test = test->next;
	}
	free_stack(&stack_a);
	return (0);
}
