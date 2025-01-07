/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:10:17 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/07 11:47:31 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list, char *move)
{
	int	tmp;

	tmp = (*list)->nb;
	(*list)->nb = (*list)->next->nb;
	(*list)->next->nb = tmp;
}

void	ft_rotate(t_list **list, char *move)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next;  
	ft_lst_last(*list)->next = tmp;
	tmp->next = NULL;
}

void	ft_rev_rotate(t_list **list, char *move)
{
	t_list	*last;
	t_list	*cur;

	last = ft_lst_last(*list);
	last->next = *list;
	cur = *list;
	while (cur->next != last)
		cur = cur->next;
	cur->next = NULL;
	*list = last;
}

void	ft_push(t_list **a, t_list **b, char *move)
{
	t_list	*tmp;

	if (!(*a))
		return ;
	ft_create_node(b, (*a)->nb);
	tmp = *a;
	*a = (*a)->next;
	free(tmp);
}