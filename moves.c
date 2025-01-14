/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:10:17 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/14 15:44:15 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list, char *move)
{
	t_list	*tmp;

	tmp = (*list)->next;
	(*list)->next = tmp->next;
	tmp->next = *list;
	*list = tmp;
	ft_printf("%s", move);
}

void	ft_rotate(t_list **list, char *move)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next;  
	ft_lstlast(*list)->next = tmp;
	tmp->next = NULL;
	ft_printf("%s", move);
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
	ft_printf("%s", move);
}

// from lst A to B
void	ft_push(t_list **a, t_list **b, char *move)
{
	t_list	*tmp;

	if (!(*a))
		return ;
	ft_lstadd_front(b, ft_lstnew((*a)->content));
	(*b)->index = (*a)->index;
	tmp = *a;
	*a = (*a)->next;
	free(tmp);
	ft_printf("%s", move);
}

void	ft_db(void (*ft)(t_list**, char*), t_list **a, t_list **b, char *m)
{
	if (*a)
		ft(a, m);
	if (*b)
		ft(b, "");
}
