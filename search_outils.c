/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_outils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bing <bing@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:20:22 by bing              #+#    #+#             */
/*   Updated: 2023/07/03 12:09:31 by bing             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// trouver le max du stack
int	find_max(t_list **stack)
{
	t_list	*current;
	int		max;

	current = *stack;
	max = ft_atoi((current)->content);
	current = current->next;
	while (current)
	{
		if (ft_atoi((current)->content) > max)
			max = ft_atoi((current)->content);
		current = current->next;
	}
	return (max);
}

// trouver le min du stack
int	find_min(t_list **stack)
{
	t_list	*current;
	int		min;

	current = *stack;
	min = ft_atoi((current)->content);
	current = current->next;
	while (current)
	{
		if (ft_atoi((current)->content) < min)
			min = ft_atoi((current)->content);
		current = current->next;
	}
	return (min);
}

// trouver l'index du nbr du stack auquel il appartient
int	find_index(long nbr, t_list **stack)
{
	t_list	*current;
	int		i;

	current = *stack;
	i = 0;
	while (current && ft_atoi(current->content) != nbr)
	{
		i++;
		current = current->next;
	}
	return (i);
}

// trouver l'index sur le stack_b, de l'element a
int	find_position_b(t_list **element, t_list **stack)
{
	t_list	*current;
	int		position;

	current = *stack;
	position = 1;
	if (ft_atoi((*element)->content) > ft_atoi((*stack)->content)
		&& ft_atoi((*element)->content) < ft_atoi(ft_lstlast(*stack)->content))
		position = 0;
	else if (ft_atoi((*element)->content) > find_max(stack)
		|| ft_atoi((*element)->content) < find_min(stack))
		position = find_index(find_max(stack), stack);
	else if (ft_atoi((*element)->content) < find_max(stack)
		&& ft_atoi((*element)->content) > find_min(stack))
	{
		while (ft_atoi(current->content) < ft_atoi((*element)->content)
			|| ft_atoi(current->next->content) > ft_atoi((*element)->content))
		{
			position++;
			current = current->next;
		}
	}
	return (position);
}

// trouver l'index sur le stack_a, de l'element b
int	find_position_a(t_list **element, t_list **stack)
{
	t_list	*current;
	int		position;

	current = *stack;
	position = 1;
	if (ft_atoi((*element)->content) < ft_atoi((*stack)->content)
		&& ft_atoi((*element)->content) > ft_atoi(ft_lstlast(*stack)->content))
		position = 0;
	else if (ft_atoi((*element)->content) > find_max(stack)
		|| ft_atoi((*element)->content) < find_min(stack))
		position = find_index(find_min(stack), stack);
	else
	{
		while (ft_atoi(current->content) > ft_atoi((*element)->content)
			|| ft_atoi(current->next->content) < ft_atoi((*element)->content))
		{
			position++;
			current = current->next;
		}
	}
	return (position);
}