/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:10:17 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/07 16:54:37 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list, char *move)
{
	int	tmp;

	tmp = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = tmp;
	ft_printf("%s\n", move);
}

void	ft_rotate(t_list **list, char *move)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next;  
	ft_lstlast(*list)->next = tmp;
	tmp->next = NULL;
	ft_printf("%s\n", move);
}

void	ft_rev_rotate(t_list **list, char *move)
{
	t_list	*last;
	t_list	*cur;

	last = ft_lstlast(*list);
	last->next = *list;
	cur = *list;
	while (cur->next != last)
		cur = cur->next;
	cur->next = NULL;
	*list = last;
	ft_printf("%s\n", move);
}

void	ft_push(t_list **a, t_list **b, char *move)
{
	t_list	*tmp;

	if (!(*a))
		return ;
	ft_lstadd_front(b, ft_lstnew((*a)->content));
	tmp = *a;
	*a = (*a)->next;
	free(tmp);
	ft_printf("%s\n", move);
}