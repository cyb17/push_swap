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
void	delete_content(void *content);
void	ft_swap(t_list **list);
void	ft_push(t_list *element, t_list *list);
void	ft_rotate(t_list *list);
void	ft_reverse_rotate(t_list *list);

#endif
