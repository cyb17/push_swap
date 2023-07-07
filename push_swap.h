/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:04:13 by yachen            #+#    #+#             */
/*   Updated: 2023/07/06 18:31:54 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stdio.h>
#include "./new_libft/libft.h"
#include "./new_libft/ft_printf.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;
int 	stringcmp(char *s1, char *s2);
void	free_tab(char **tab);
void	free_stack(t_stack **stack);
int		already_sorted(t_stack *stack_a);
int		lst_size(t_stack *stack);
void	parsing(int argc, char **argv);
t_stack	*lst_addnew(int content);
void	lst_addback(t_stack **lst, t_stack *new_stack);
void	lst_addfront(t_stack **lst, t_stack *new_stack);
t_stack	*make_normal(int argc, char **argv);
t_stack	*make_string(char **argv);
void	ft_error(void);
t_stack	*lst_last(t_stack *stack);
void	ft_swap(t_stack **list);
void	ft_push(t_stack **element, t_stack **list);
void	ft_rotate(t_stack **list);
void	ft_reverse_rotate(t_stack **list);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
int		find_max(t_stack **stack);
int		find_min(t_stack **stack);
int		find_index(long nbr, t_stack **stack);
int		find_position_b(t_stack **element, t_stack **stack);
int		find_position_a(t_stack **element, t_stack **stack);
void	sort_to_b(t_stack **a, t_stack **b);
void	sort_to_a(t_stack **a, t_stack **b);
void	sort(t_stack **stack_a);

#endif