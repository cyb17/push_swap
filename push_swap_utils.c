/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:52:26 by yachen            #+#    #+#             */
/*   Updated: 2023/07/13 11:12:18 by yachen           ###   ########.fr       */
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
