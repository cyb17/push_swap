/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:46:54 by yachen            #+#    #+#             */
/*   Updated: 2023/07/10 14:31:36 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "./new_libft/libft.h"
# include "./new_libft/ft_printf.h"
# include "./new_libft/get_next_line.h"
# include "./push_swap.h"

char	*read_instruc(int fd);
//int		parsing_instruct(char **inst);
void	inst_sp(char *str, t_stack **stack_a, t_stack **stack_b);
void	inst_r(char *str, t_stack **stack_a, t_stack **stack_b);
void	ft_checker(t_stack **stack_a, t_stack **stack_b, char **instruct);

#endif