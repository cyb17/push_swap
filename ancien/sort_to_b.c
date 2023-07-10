/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:56:22 by yachen            #+#    #+#             */
/*   Updated: 2023/07/10 14:42:13 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_rr(t_stack **a, t_stack **b, t_stack **elem)
{
	while (*a != *elem && find_position_b(elem, b) > 0)
		rr(a, b);
	while (*a != *elem)
		ra(a);
	while (find_position_b(elem, b) > 0)
		rb(b);
	pb(a, b);
	return (-1);
}

static int	sort_rrr(t_stack **a, t_stack **b, t_stack **elem)
{	
	while (*a != *elem && find_position_b(elem, b) > 0)
		rrr(a, b);
	while (*a != *elem)
		rra(a);
	while (find_position_b(elem, b) > 0)
		rrb(b);
	pb(a, b);
	return (-1);
}

static int	sort_rrarb(t_stack **a, t_stack **b, t_stack **elem)
{
	while (*a != *elem)
		rra(a);
	while (find_position_b(elem, b) > 0)
		rb(b);
	pb(a, b);
	return (-1);
}

static int	sort_rarrb(t_stack **a, t_stack **b, t_stack **elem)
{
	while (*a != *elem)
		ra(a);
	while (find_position_b(elem, b) > 0)
		rrb(b);
	pb(a, b);
	return (-1);
}

// tant que stack_a a plus de 3 elements
// fonction push elem_a a la bonne position sur stack_b
// et trie les 3 elements restant de stack_a
void	sort_to_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		step;

	while (lst_size(*a) > 3 && already_sorted(*a) == 0)
	{
		tmp = *a;
		step = calculator_b(a, b);
		while (step >= 0)
		{
			if (step == caseb_rr(a, b, &tmp))
				step = sort_rr(a, b, &tmp);
			else if (step == caseb_rrr(a, b, &tmp))
				step = sort_rrr(a, b, &tmp);
			else if (step == caseb_rrarb(a, b, &tmp))
				step = sort_rrarb(a, b, &tmp);
			else if (step == caseb_rarrb(a, b, &tmp))
				step = sort_rarrb(a, b, &tmp);
			else
				tmp = tmp->next;
		}
	}
	if (already_sorted(*a) == 0)
		sort_3(a);
}
