/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bing <bing@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:40:48 by yachen            #+#    #+#             */
/*   Updated: 2023/06/23 13:41:25 by bing             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sort(t_list *stack_a)
{
	t_list	*current;
	t_list	*tmp;

	current = stack_a;
	while (current->next)
	{
		tmp = current;
		current = current->next;
		if (ft_atoi(tmp->content) > ft_atoi(current->content))
			return (0);
	}
	ft_printf("The stack is already sorted :)");
	return (1);
}

void	sort_3(t_list **stack_a)
{
	int	nb1;
	int nb2;
	int nb3;

	nb1 = ft_atoi((*stack_a)->content);
	nb2 = ft_atoi((*stack_a)->next->content);
	nb3 = ft_atoi(ft_lstlast(*stack_a)->content);
	if (nb1 > nb2 && nb1 < nb3)
		sa(stack_a);
	else if (nb1 > nb2 && nb2 > nb3)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (nb1 > nb2 && nb1 > nb3 && nb2 < nb3)
		ra(stack_a);
	else if (nb1 < nb2 && nb1 < nb3 && nb2 > nb3)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (nb1 < nb2 && nb1 > nb3)
		rra(stack_a);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
	if (ft_atoi((*stack_a)->content) > ft_atoi((*stack_a)->next->content))
	{
		sa(stack_a);
		tmp = *stack_a;
		*stack_a = (*stack_a)->next; 
		sort_3(stack_a);
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_b, stack_a);
	if (ft_atoi((*stack_a)->content) > ft_atoi((*stack_a)->next->content))
	{
		sa(stack_a);
		tmp = *stack_a;
		*stack_a = (*stack_a)->next; 
		sort_4(stack_a, stack_b);
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}

void	simply_sort(int argc, t_list **stack_a, t_list **stack_b)
{
	if (argc == 3)
		sa(stack_a);
	else if (argc == 4)
		sort_3(stack_a);
	else if (argc == 5)
		sort_4(stack_a, stack_b);
	else if (argc == 6)
		sort_5(stack_a, stack_b);
}
