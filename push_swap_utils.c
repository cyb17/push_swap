/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:52:26 by yachen            #+#    #+#             */
/*   Updated: 2023/06/21 14:50:27 by yachen           ###   ########.fr       */
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

t_list	*ft_make_stack(int argc, char **argv)
{
	t_list	*stack;
	t_list	*new;
	int		nbr;

	nbr = 0;
	stack = NULL;
	new = NULL;
	while (--argc > 1)
	{
		nbr = ft_atoi(argv[argc]);
		new = ft_lstnew(&nbr);
		printf("%d\n", *((int *)(new->content)));
		ft_lstadd_front(&stack, new);
		printf("%d\n", *((int *)(stack->next->content)));
	}
	return (stack);
}
