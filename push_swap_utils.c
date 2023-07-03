/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bing <bing@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:52:26 by yachen            #+#    #+#             */
/*   Updated: 2023/07/03 16:42:10 by bing             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

t_list	*make_stack(int argc, char **argv)
{
	t_list	*list;
	t_list	*new;

	list = ft_lstnew(argv[--argc]);
	new = NULL;
	while (--argc > 0)
	{
		new = ft_lstnew(argv[argc]);
		ft_lstadd_front(&list, new);
	}
	return (list);
}

int	already_sorted(t_list *stack_a)
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
	return (1);
}

void	free_stack(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
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

void	sort(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && already_sorted(*stack_a) == 0)
		pb(stack_a, &stack_b);
	if (ft_lstsize(*stack_a) > 3 && already_sorted(*stack_a) == 0)
		pb(stack_a, &stack_b);
	sort_to_b(stack_a, &stack_b);
	sort_to_a(stack_a, &stack_b);
}