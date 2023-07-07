/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_outils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:20:22 by bing              #+#    #+#             */
/*   Updated: 2023/07/06 14:41:28 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// trouver le max du stack
int	find_max(t_stack **stack)
{
	t_stack	*current;
	int		max;

	current = *stack;
	max = current->nbr;
	current = current->next;
	while (current)
	{
		if (current->nbr > max)
			max = current->nbr;
		current = current->next;
	}
	return (max);
}

// trouver le min du stack
int	find_min(t_stack **stack)
{
	t_stack	*current;
	int		min;

	current = *stack;
	min = current->nbr;
	current = current->next;
	while (current)
	{
		if (current->nbr < min)
			min = current->nbr;
		current = current->next;
	}
	return (min);
}

// trouver l'index du nbr du stack auquel il appartient
int	find_index(long nbr, t_stack **stack)
{
	t_stack	*current;
	int		i;

	current = *stack;
	i = 0;
	while (current && current->nbr != nbr)
	{
		i++;
		current = current->next;
	}
	return (i);
}

// trouver l'index sur le stack_b, de l'element a
int	find_position_b(t_stack **element, t_stack **stack)
{
	t_stack	*current;
	int		position;

	current = *stack;
	position = 1;
	if ((*element)->nbr > (*stack)->nbr
		&& (*element)->nbr < lst_last(*stack)->nbr)
		position = 0;
	else if ((*element)->nbr > find_max(stack)
		|| (*element)->nbr < find_min(stack))
		position = find_index(find_max(stack), stack);
	else if ((*element)->nbr < find_max(stack)
		&& (*element)->nbr > find_min(stack))
	{
		while (current->nbr < (*element)->nbr
			|| current->next->nbr > (*element)->nbr)
		{
			position++;
			current = current->next;
		}
	}
	return (position);
}

// trouver l'index sur le stack_a, de l'element b
int	find_position_a(t_stack **element, t_stack **stack)
{
	t_stack	*current;
	int		position;

	current = *stack;
	position = 1;
	if ((*element)->nbr < (*stack)->nbr
		&& (*element)->nbr > lst_last(*stack)->nbr)
		position = 0;
	else if ((*element)->nbr > find_max(stack)
		|| (*element)->nbr < find_min(stack))
		position = find_index(find_min(stack), stack);
	else
	{
		while (current->nbr > (*element)->nbr
			|| current->next->nbr < (*element)->nbr)
		{
			position++;
			current = current->next;
		}
	}
	return (position);
}