/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:00:46 by yachen            #+#    #+#             */
/*   Updated: 2023/07/07 11:49:42 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **list)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	
	if (!(*list) || !(*list)->next)
		return ;
	tmp1 = *list;
	tmp2 = (*list)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*list = tmp2;

}

void	ft_push(t_stack **element, t_stack **list)
{
	t_stack	*tmp;

	if (!(*element))
		return ;
	tmp = *element;
	*element = (*element)->next;
	lst_addfront(list, tmp);
}

void	ft_rotate(t_stack **list)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp2 = (*list)->next;
	tmp1 = lst_last(*list);
	tmp1->next = *list;
	(*list)->next = NULL;
	*list = tmp2;
}

void	ft_reverse_rotate(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*current;

	current = *list;
	while (current->next)
	{	
		tmp = current;
		current = current->next;
	}
	tmp->next = NULL;
	current->next = *list;
	*list = current;
}

void	sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}

void	rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}

