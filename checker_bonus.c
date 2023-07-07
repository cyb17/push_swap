/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:44:59 by yachen            #+#    #+#             */
/*   Updated: 2023/07/07 19:23:28 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// fonction qui lit les instructions
char	*read_instruc(int fd)
{
	char	*string;
	char	*line;
	char	*tmp;

	string = NULL;
	line = NULL;
	tmp = NULL;
	line = get_next_line(fd);
	tmp = line;
	while (1)
	{
		string = get_next_line(fd);
		line = ft_strjoin(line, string);
		if (!line)
			return (NULL);
		free(tmp);
		if (string != NULL)
			free(string);
		else
			break ;
	}
	return (line);
}

int	parsing_instruct(char *line)
{
	char	**check;
	char	**instruct;
	int		i;

	check = ft_split("sa\nsb\nss\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n", '\n');
	if (!check)
		return (0);
	instruct = ft_split(line, '\n');
	if (!instruct)
		return (0);
	while (*instruct)
	{
		i = 0;
		while (check[i] && stringcmp(*instruct, check[i]) == 1)
			i++;
		if (check[i] == NULL)
		{
			free_tab(instruct);
			free_tab(check);
			return (0);
		}
		inst++;
	}
	free_tab(instruct);
	free_tab(check);
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
		rb(stack_a);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\0')
		rr(stack_a, stack_b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		rra(stack_a);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		rrb(stack_a);
	else if (str[0] == 'r' && str[1] == 'r' && str[3] == 'r')
		rrr(stack_a, stack_b);
}

void	ft_checker(t_stack **stack_a, t_stack **stack_b, char **instruct)
{
	int		i;
	char	**inst;
	
	i = 0;
	inst = ft_split(*instruct, '\n');
	if (parsing_instruct(inst) == 0)
	{
		free_tab(inst);
		free_stack(stack_a);
		free(*instruct);
		ft_error();
	}
	while (inst[i])
	{
		if (inst[i][0] == 's' || inst[i][0] == 'p')
			inst_sp(inst[i], stack_a, stack_b);
		else 
			inst_r(inst[i], stack_a, stack_a);
		i++;
	}
	free_tab(inst);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*instruct;

	stack_a = NULL;
	stack_b = NULL;
	instruct = NULL;
	parsing(argc, argv);
	instruct = read_instruc(0);
	parsing_instruct(instruct);
	if (argc == 2)
		stack_a = make_string(argv);
	else
		stack_a = make_normal(argc, argv);
	appl_instruct(&stack_a, &stack_b, &instruct);
	if (already_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free(instruct);
	return (0);
}