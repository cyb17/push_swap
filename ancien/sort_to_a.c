/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:56:49 by yachen            #+#    #+#             */
/*   Updated: 2023/07/10 14:36:06 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_rr(t_stack **a, t_stack **b, t_stack **elem)
{
	while (*b != *elem && find_position_a(elem, a) > 0)
		rr(a, b);
	while (*b != *elem)
		rb(b);
	while (find_position_a(elem, a) > 0)
		ra(a);
	pa(b, a);
	return (-1);
}

static int	sort_rrr(t_stack **a, t_stack **b, t_stack **elem)
{	
	while (*b != *elem && find_position_a(elem, a) > 0)
		rrr(a, b);
	while (*b != *elem)
		rrb(b);
	while (find_position_a(elem, a) > 0)
		rra(a);
	pa(b, a);
	return (-1);
}

static int	sort_rrbra(t_stack **a, t_stack **b, t_stack **elem)
{
	while (*b != *elem)
		rrb(b);
	while (find_position_a(elem, a) > 0)
		ra(a);
	pa(b, a);
	return (-1);
}

static int	sort_rbrra(t_stack **a, t_stack **b, t_stack **elem)
{
	while (*b != *elem)
		rb(b);
	while (find_position_a(elem, a) > 0)
		rra(a);
	pa(b, a);
	return (-1);
}

// fonction push elem_b a la bonne position sur stack_a
void	sort_to_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		step;

	while (*b)
	{
		tmp = *b;
		step = calculator_a(a, b);
		while (step >= 0)
		{
			if (step == case_rr(a, b, &tmp))
				step = sort_rr(a, b, &tmp);
			else if (step == case_rrr(a, b, &tmp))
				step = sort_rrr(a, b, &tmp);
			else if (step == case_rrbra(a, b, &tmp))
				step = sort_rrbra(a, b, &tmp);
			else if (step == case_rbrra(a, b, &tmp))
				step = sort_rbrra(a, b, &tmp);
			else
				tmp = tmp->next;
		}
	}
	sort_a(a);
}
