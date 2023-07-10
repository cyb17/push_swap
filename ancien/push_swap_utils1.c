/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:52:26 by yachen            #+#    #+#             */
/*   Updated: 2023/07/10 14:22:26 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	already_sorted(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*tmp;

	current = stack_a;
	tmp = NULL;
	while (current->next)
	{
		tmp = current;
		current = current->next;
		if (tmp->nbr > current->nbr)
			return (0);
	}
	return (1);
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
