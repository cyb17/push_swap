/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bing <bing@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:56:22 by bing              #+#    #+#             */
/*   Updated: 2023/07/03 14:29:23 by bing             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	case_rr(t_list **a, t_list **b, t_list **element_a)
{
	int	i;

	i = find_position_b(element_a, b);
	if (i < find_index(ft_atoi((*element_a)->content), a))
		i = find_index(ft_atoi((*element_a)->content), a);
	return (i);
}

static int	case_rrr(t_list **a, t_list **b, t_list **element_a)
{
	int	i;

	i = 0;
	if (find_position_b(element_a, b) != 0)
		i = ft_lstsize(*b) - find_position_b(element_a, b);
	if ((i < ft_lstsize(*a) - (find_index(ft_atoi((*element_a)->content), a))) 
		&& find_index(ft_atoi((*element_a)->content), a) != 0)
		i = ft_lstsize(*a) - (find_index(ft_atoi((*element_a)->content), a));
	return (i);
}

static int	case_rrarb(t_list **a, t_list **b, t_list **element_a)
{
	int	i;

	i = 0;
	if (find_index(ft_atoi((*element_a)->content), a) != 0)
		i = ft_lstsize(*a) - (find_index(ft_atoi((*element_a)->content), a));
	i += find_position_b(element_a, b);
	return (i);
}

static int	case_rarrb(t_list **a, t_list **b, t_list **element_a)
{
	int	i;

	i = 0;
	if (find_position_b(element_a, b) != 0)
		i = ft_lstsize(*b) - find_position_b(element_a, b);
	i += find_index(ft_atoi((*element_a)->content), a);
	return (i);
}

static int	sort_rr(t_list **a, t_list **b, t_list **elem)
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

static int	sort_rrr(t_list **a, t_list **b, t_list **elem)
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

static int	sort_rrarb(t_list **a, t_list **b, t_list **elem)
{
	while (*a != *elem)
		rra(a);
	while (find_position_b(elem, b) > 0)
		rb(b);
	pb(a, b);
	return (-1);
}

static int	sort_rarrb(t_list **a, t_list **b, t_list **elem)
{
	while (*a != *elem)
		ra(a);
	while (find_position_b(elem, b) > 0)
		rrb(b);
	pb(a, b);
	return (-1);
}

// fonction qui trouve la plus courte suite d'operations existant du stack_a
static int	calculator(t_list **a, t_list **b)
{
	t_list	*elem;
	int step;

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

// tant que stack_a a plus de 3 elements
// fonction push elem_a a la bonne position sur stack_b
// et trie les 3 elements restant de stack_a
void	sort_to_b(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		step;

	while (ft_lstsize(*a) > 3 && already_sorted(*a) == 0)
	{
		tmp = *a;
		step = calculator(a, b);
		while (step >= 0)
		{
			if (step == case_rr(a, b, &tmp))
				step = sort_rr(a, b, &tmp);
			else if (step == case_rrr(a, b, &tmp))
				step = sort_rrr(a, b, &tmp);
			else if (step == case_rrarb(a, b, &tmp))
				step = sort_rrarb(a, b, &tmp);
			else if (step == case_rarrb(a, b, &tmp))
				step = sort_rarrb(a, b, &tmp);
			else
				tmp = tmp->next;
		}
	}
	if (already_sorted(*a) == 0)
		sort_3(a);
}
