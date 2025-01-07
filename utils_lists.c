/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:01:26 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/07 11:46:54 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_node(t_list **list, int nb)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	if (!*list)
		*list = node;
	else
		ft_lst_last(*list)->next = node;
	node->nb = nb;
	node->next = NULL;
}

t_list	*ft_lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lst_free(t_list **list)
{
	t_list	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	list = NULL;
	free(tmp);
	tmp = NULL;
}