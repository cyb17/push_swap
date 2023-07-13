/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_b2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:56:22 by yachen            #+#    #+#             */
/*   Updated: 2023/07/13 11:08:26 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rr(t_stack **a, t_stack **b, t_stack **element_a)
{
	int	i;

	i = find_position_b(element_a, b);
	if (i < find_index((*element_a)->nbr, a))
		i = find_index((*element_a)->nbr, a);
	return (i);
}

int	case_rrr(t_stack **a, t_stack **b, t_stack **element_a)
{
	int	i;

	i = 0;
	if (find_position_b(element_a, b) != 0)
		i = lst_size(*b) - find_position_b(element_a, b);
	if ((i < lst_size(*a) - (find_index((*element_a)->nbr, a)))
		&& find_index((*element_a)->nbr, a) != 0)
		i = lst_size(*a) - (find_index((*element_a)->nbr, a));
	return (i);
}

int	case_rrarb(t_stack **a, t_stack **b, t_stack **element_a)
{
	int	i;

	i = 0;
	if (find_index((*element_a)->nbr, a) != 0)
		i = lst_size(*a) - (find_index((*element_a)->nbr, a));
	i += find_position_b(element_a, b);
	return (i);
}

int	case_rarrb(t_stack **a, t_stack **b, t_stack **element_a)
{
	int	i;

	i = 0;
	if (find_position_b(element_a, b) != 0)
		i = lst_size(*b) - find_position_b(element_a, b);
	i += find_index((*element_a)->nbr, a);
	return (i);
}

// fonction qui trouve la plus courte suite d'operations existant du stack_a
int	calculator_b(t_stack **a, t_stack **b)
{
	t_stack	*elem;
	int		step;

	elem = *a;
	step = case_rrr(a, b, &elem);
	while (elem)
	{
		if (case_rr(a, b, &elem) < step)
			step = case_rr(a, b, &elem);
		if (case_rrr(a, b, &elem) < step)
			step = case_rrr(a, b, &elem);
		if (case_rrarb(a, b, &elem) < step)
			step = case_rrarb(a, b, &elem);
		if (case_rarrb(a, b, &elem) < step)
			step = case_rarrb(a, b, &elem);
		elem = elem->next;
	}
	return (step);
}
