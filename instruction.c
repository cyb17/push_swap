/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bing <bing@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:00:46 by yachen            #+#    #+#             */
/*   Updated: 2023/06/22 12:01:29 by bing             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list)
{
	t_list	*tmp1;
	t_list	*tmp2;
	
	if (!(*list) || !(*list)->next)
		return ;
	tmp1 = *list;
	tmp2 = (*list)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*list = tmp2;

}

void	ft_push(t_list *element, t_list *list)
{
	t_list	*tmp;

	if (!element)
		return ;
	tmp = element;
	element = element->next;
	ft_lstadd_front(&list, tmp);
}

void	ft_rotate(t_list *list)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = list;
	tmp2 = list->next;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp1->next = list;
	list->next = NULL;
	list = tmp2;
}

void	ft_reverse_rotate(t_list *list)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp1 = list;
	tmp3 = list;
	while (tmp1->next)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp2->next = NULL;
	tmp1->next = tmp3;
	list = tmp1;
}
