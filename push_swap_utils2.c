/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:52:26 by yachen            #+#    #+#             */
/*   Updated: 2023/07/13 12:18:35 by yachen           ###   ########.fr       */
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

//fonction trie stack_a du plus petit au plus grand
void	sort_a(t_stack **stack_a)
{
	int	min;
	int	index_min;

	min = find_min(stack_a);
	index_min = find_index(min, stack_a);
	if (index_min < lst_size(*stack_a) - index_min)
	{
		while ((*stack_a)->nbr != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->nbr != min)
			rra(stack_a);
	}
}

void	sort_3(t_stack **stack_a)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr
		&& (*stack_a)->nbr < lst_last(*stack_a)->nbr)
		sa(stack_a);
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr
		&& (*stack_a)->next->nbr > lst_last(*stack_a)->nbr)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr
		&& (*stack_a)->nbr > lst_last(*stack_a)->nbr
		&& (*stack_a)->next->nbr < lst_last(*stack_a)->nbr)
		ra(stack_a);
	else if ((*stack_a)->nbr < (*stack_a)->next->nbr
		&& (*stack_a)->nbr < lst_last(*stack_a)->nbr
		&& (*stack_a)->next->nbr > lst_last(*stack_a)->nbr)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->nbr < (*stack_a)->next->nbr
		&& (*stack_a)->nbr > lst_last(*stack_a)->nbr)
		rra(stack_a);
}
