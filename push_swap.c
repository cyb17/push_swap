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

	parsing(argc, argv);
	stack_a = make_stack(argc, argv);
	t_list	*tmp = stack_a;
	while (tmp)
	{
		printf("%p\n", tmp);
		printf("%p\n", (char *)tmp->content);
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&stack_a, delete_content);
	printf("%p\n", stack_a);
	

	return (0);
}
