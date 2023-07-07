/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:56:49 by yachen            #+#    #+#             */
/*   Updated: 2023/07/06 14:39:49 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	case_rr(t_stack **a, t_stack **b, t_stack **element_b)
{
	int	i;

	i = find_position_a(element_b, a);
	if (i < find_index((*element_b)->nbr, b))
		i = find_index((*element_b)->nbr, b);
	return (i);
}

static int	case_rrr(t_stack **a, t_stack **b, t_stack **element_b)
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

static int	case_rrbra(t_stack **a, t_stack **b, t_stack **element_b)
{
	int	i;

	i = 0;
	if (find_index((*element_b)->nbr, b) != 0)
		i = lst_size(*b) - (find_index((*element_b)->nbr, b));
	i += find_position_a(element_b, a);
	return (i);
}

static int	case_rbrra(t_stack **a, t_stack **b, t_stack **element_b)
{
	int	i;

	i = 0;
	if (find_position_a(element_b, a) != 0)
		i = lst_size(*a) - find_position_a(element_b, a);
	i += find_index((*element_b)->nbr, b);
	return (i);
}

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

// fonction qui trouve la plus courte suite d'operations existant du stack_b
static int	calculator(t_stack **a, t_stack **b)
{
	t_stack	*elem;
	int step;

	elem = *b;
	step = case_rrr(a, b, &elem);
	while (elem)
	{
		if(case_rr(a, b, &elem) < step)
			step = case_rr(a, b, &elem);
		if (case_rrr(a, b, &elem) < step)
			step = case_rrr(a, b, &elem);
		if (case_rrbra(a, b, &elem) < step)
			step = case_rrbra(a, b, &elem);
		if (case_rbrra(a, b, &elem) < step)
			step = case_rbrra(a, b, &elem);
		elem = elem->next;
	}
	return (step);
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

// fonction push elem_b a la bonne position sur stack_a
void	sort_to_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		step;

	while (*b)
	{
		tmp = *b;
		step = calculator(a, b);
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
