/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:46:00 by yachen            #+#    #+#             */
/*   Updated: 2023/06/21 15:32:38 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stdio.h>
#include "./new_libft/libft.h"
#include "./new_libft/ft_printf.h"

void	parsing(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);
t_list	*make_stack(int argc, char **argv);
void	free_stack(t_list **list);
void	ft_swap(t_list **list);
void	ft_push(t_list **element, t_list **list);
void	ft_rotate(t_list **list);
void	ft_reverse_rotate(t_list **list);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		already_sort(t_list *stack_a);
void	simply_sort(int argc, t_list **stack_a, t_list **stack_b);

#endif
