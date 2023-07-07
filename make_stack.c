/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:22:31 by yachen            #+#    #+#             */
/*   Updated: 2023/07/06 15:04:07 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_addnew(int content)
{
	t_stack	*new;
	
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = content;
	new->next = NULL;
	return (new);
}

void	lst_addback(t_stack **lst, t_stack *new_stack)
{
	t_stack	*tmp;

	tmp = NULL;
	if (*lst == NULL)
	{
		*lst = new_stack;
		return ;
	}
	tmp = *lst;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = new_stack;
}

t_stack	*make_normal(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*new;
	int	i;

	stack = NULL;
	new = NULL;
	i = 1;
	while (i < argc)
	{
		new = lst_addnew(ft_atoi(argv[i]));
		if (!new)
		{
			if (stack)
				free_stack(&stack);
			ft_error();
		}
		lst_addback(&stack, new);
		i++;
	}
	return (stack);
}

t_stack	*make_string(char **argv)
{
	t_stack	*stack;
	t_stack	*new;
	char	**string;
	int		i;
	
	stack = NULL;
	new = NULL;
	string = ft_split(argv[1], ' ');
	if (!string)
		ft_error();
	i = 0;
	while (string[i])
	{
		new = lst_addnew(ft_atoi(string[i]));
		if (!new)
		{
			if (stack)
				free_stack(&stack);
			ft_error();
		}
		lst_addback(&stack, new);
		i++;
	}
	free_tab(string);
	return (stack);
}