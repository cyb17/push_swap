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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	parsing(argc, argv);
	stack_a = make_stack(argc, argv);
	if (already_sort(stack_a) == 1)
	{
		stack_b = ft_lstnew(NULL);
		free_stack(&stack_a);
		free_stack(&stack_b);
		exit(0);
	}
	stack_b = NULL;
	if (argc <= 6)
		simply_sort(argc, &stack_a, &stack_b);
	t_list	*test = stack_a;
	while (test)
	{
		printf("%s ", (char *)test->content);
		test = test->next;
	}
	return (0);
}
