/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:17:35 by yachen            #+#    #+#             */
/*   Updated: 2023/07/10 14:18:28 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	if (!tmp)
		return (size);
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

t_stack	*lst_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack -> next != NULL)
		stack = stack -> next;
	return (stack);
}

void	lst_addfront(t_stack **lst, t_stack *new_stack)
{
	new_stack -> next = *lst;
	*lst = new_stack;
}

void	ft_error(void)
{
	ft_printf("Error");
	exit(1);
}

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (lst_size(*stack_a) == 2)
		sa(stack_a);
	else
	{
		if (lst_size(*stack_a) > 3 && already_sorted(*stack_a) == 0)
			pb(stack_a, &stack_b);
		if (lst_size(*stack_a) > 3 && already_sorted(*stack_a) == 0)
			pb(stack_a, &stack_b);
		sort_to_b(stack_a, &stack_b);
		sort_to_a(stack_a, &stack_b);
	}
}
