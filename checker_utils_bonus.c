/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:13:59 by yachen            #+#    #+#             */
/*   Updated: 2023/07/18 13:12:47 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*read_instruct(int fd)
{
	char	*str1;
	char	*str2;
	char	*tmp;

	str1 = get_next_line(fd);
	while (1)
	{
		tmp = str1;
		str2 = get_next_line(fd);
		if (str2 == NULL)
			return (str1);
		str1 = ft_strjoin(str1, str2);
		free(tmp);
		free(str2);
	}
}

int	find_substr(char *instruct)
{
	char	*right_inst;
	char	**tab;
	char	*str;
	char	**tmp;

	str = instruct;
	tab = ft_split(str, '\n');
	if (!tab)
		return (0);
	tmp = tab;
	right_inst = "\nsa\nsb\nss\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n";
	while (*tab)
	{
		if (ft_strnstr(right_inst, *tab, ft_strlen(right_inst)) == 0)
		{
			free_tab(tmp);
			return (0);
		}
		tab++;
	}
	free_tab(tmp);
	return (1);
}

void	inst_sp(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (str[0] == 's')
	{
		if (str[1] == 'a')
			sa(stack_a);
		else if (str[1] == 'b')
			sb(stack_a);
		else
			ss(stack_a, stack_b);
	}
	if (str[0] == 'p')
	{
		if (str[1] == 'a')
			pa(stack_b, stack_a);
		else if (str[1] == 'b')
			pb(stack_a, stack_b);
	}
}

void	inst_r(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (str[0] == 'r' && str[1] == 'a')
		ra(stack_a);
	else if (str[0] == 'r' && str[1] == 'b')
		rb(stack_b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\0')
		rr(stack_a, stack_b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		rra(stack_a);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		rrb(stack_b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		rrr(stack_a, stack_b);
}

void	apply_inst(char *instruct, t_stack **stack_a, t_stack **stack_b)
{
	char	**tab;
	char	*str;
	int		i;

	str = instruct;
	tab = ft_split(str, '\n');
	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		if (*(tab[i]) == 's' || *(tab[i]) == 'p')
			inst_sp(tab[i], stack_a, stack_b);
		else
			inst_r(tab[i], stack_a, stack_b);
		i++;
	}
	free_tab(tab);
}
