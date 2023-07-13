/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:57:18 by yachen            #+#    #+#             */
/*   Updated: 2023/07/13 13:24:58 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_instruct(char *instruct)
{
	int	i;

	i = 0;
	while (instruct[i])
	{
		if ((instruct[i] == '\n' && instruct[i + 1] == '\n')
			|| instruct[0] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	check_instruct2(char *instruct)
{
	if (instruct != NULL
		&& (check_instruct(instruct) == 0 || find_substr(instruct) == 0))
	{
		free(instruct);
		ft_error();
	}
}

void	check_stack_b(t_stack **stack_b)
{
	if (*stack_b == NULL)
		return ;
	else
		free_stack(stack_b);
}

void	check_stack_a2(char *instruct, t_stack *stack_a)
{
	if (lst_size(stack_a) == 1 && instruct == NULL)
	{
		free_stack(&stack_a);
		exit(0);
	}
	else if (lst_size(stack_a) == 1 && instruct != NULL)
	{
		free(instruct);
		free_stack(&stack_a);
		exit(0);
	}
}

void	check_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	if (already_sorted(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
