/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:56:49 by yachen            #+#    #+#             */
/*   Updated: 2023/07/13 11:10:46 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	casea_rr(t_stack **a, t_stack **b, t_stack **element_b)
{
	int	i;

	i = find_position_a(element_b, a);
	if (i < find_index((*element_b)->nbr, b))
		i = find_index((*element_b)->nbr, b);
	return (i);
}

int	casea_rrr(t_stack **a, t_stack **b, t_stack **element_b)
{
	int	i;

	i = 0;
	if (find_position_a(element_b, a) != 0)
		i = lst_size(*a) - find_position_a(element_b, a);
	if ((i < lst_size(*b) - (find_index((*element_b)->nbr, b)))
		&& find_index((*element_b)->nbr, b) != 0)
		i = lst_size(*b) - (find_index((*element_b)->nbr, b));
	return (i);
}

int	case_rrbra(t_stack **a, t_stack **b, t_stack **element_b)
{
	int	i;

	i = 0;
	if (find_index((*element_b)->nbr, b) != 0)
		i = lst_size(*b) - (find_index((*element_b)->nbr, b));
	i += find_position_a(element_b, a);
	return (i);
}

int	case_rbrra(t_stack **a, t_stack **b, t_stack **element_b)
{
	int	i;

	i = 0;
	if (find_position_a(element_b, a) != 0)
		i = lst_size(*a) - find_position_a(element_b, a);
	i += find_index((*element_b)->nbr, b);
	return (i);
}

// fonction qui trouve la plus courte suite d'operations existant du stack_b
int	calculator_a(t_stack **a, t_stack **b)
{
	t_stack	*elem;
	int		step;

	elem = *b;
	step = casea_rrr(a, b, &elem);
	while (elem)
	{
		if (casea_rr(a, b, &elem) < step)
			step = casea_rr(a, b, &elem);
		if (casea_rrr(a, b, &elem) < step)
			step = casea_rrr(a, b, &elem);
		if (case_rrbra(a, b, &elem) < step)
			step = case_rrbra(a, b, &elem);
		if (case_rbrra(a, b, &elem) < step)
			step = case_rbrra(a, b, &elem);
		elem = elem->next;
	}
	return (step);
}
