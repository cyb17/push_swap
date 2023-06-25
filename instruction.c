/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bing <bing@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:00:46 by yachen            #+#    #+#             */
/*   Updated: 2023/06/22 12:01:29 by bing             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list)
{
	t_list	*tmp1;
	t_list	*tmp2;
	
	if (!(*list) || !(*list)->next)
		return ;
	tmp1 = *list;
	tmp2 = (*list)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*list = tmp2;

}

void	ft_push(t_list **element, t_list **list)
{
	t_list	*tmp;

	if (!(*element))
		return ;
	tmp = *element;
	*element = (*element)->next;
	ft_lstadd_front(list, tmp);
}

void	ft_rotate(t_list **list)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp2 = (*list)->next;
	tmp1 = ft_lstlast(*list);
	tmp1->next = *list;
	(*list)->next = NULL;
	*list = tmp2;
}

void	ft_reverse_rotate(t_list **list)
{
	t_list	*tmp;
	t_list	*current;

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

void	sa(t_list **stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_list **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	ft_push(stack_b, stack_a);
	printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b);
	printf("pb\n");
}

void	ra(t_list **stack_a)
{
	ft_rotate(stack_a);
	printf("ra\n");
}

void	rb(t_list **stack_b)
{
	ft_rotate(stack_b);
	printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	printf("rr\n");
}

void	rra(t_list **stack_a)
{
	ft_reverse_rotate(stack_a);
	printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	ft_reverse_rotate(stack_b);
	printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	printf("rrr\n");
}

