/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:46:54 by yachen            #+#    #+#             */
/*   Updated: 2023/07/13 13:23:26 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "./new_libft/libft.h"
# include "./new_libft/ft_printf.h"
# include "./new_libft/get_next_line.h"
# include "./push_swap.h"

char	*read_instruct(int fd);
int		check_instruct(char *instruct);
void	check_instruct2(char *instruct);
void	check_stack_b(t_stack **stack_b);
void	check_stack_a(t_stack *stack_a, t_stack *stack_b);
void	check_stack_a2(char *instruct, t_stack *stack_a);
int		find_substr(char *instruct);
void	inst_sp(char *str, t_stack **stack_a, t_stack **stack_b);
void	inst_r(char *str, t_stack **stack_a, t_stack **stack_b);
void	apply_inst(char *instruct, t_stack **stack_a, t_stack **stack_b);
void	check_stack_b(t_stack **stack_b);

#endif