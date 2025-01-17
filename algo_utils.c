/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:55:32 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/17 19:12:24 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_get_max(t_list *a)
{
	t_list	*max;

	max = a;
	while (a)
	{
		if (a->content > max->content)
			max = a;
		a = a->next;
	}
	return (max);
}

t_list	*ft_get_min(t_list *a)
{
	t_list	*min;

	min = a;
	while (a)
	{
		if (a->content < min->content)
			min = a;
		a = a->next;
	}
	return (min);
}

int	ft_get_dist(t_list *a, t_list *target)
{
	int	dist;

	dist = 0;
	while (a && a != target)
	{
		dist += 1;
		a = a->next;
	}
	return (dist);
}

void	ft_move_to_top(t_list **a, t_list *target)
{
	int		dist;
	int		size;

	dist = ft_get_dist(*a, target);
	size = ft_lstsize(*a);
	if (dist > size / 2)
	{
		while (dist++ < size)
			ft_rev_rotate(a, "rra\n");
	}
	else
	{
		while (dist--)
			ft_rotate(a, "ra\n");
	}
}
// search the closer element of lst for node
t_list	*ft_get_closer(t_list *lst, t_list *node)
{
	t_list	*closer;

	closer = lst;
	while (lst)
	{
		if (node->index - closer->index > node->index - lst->index)
			closer = lst;
		lst = lst->next;
	}
	return (closer);
}