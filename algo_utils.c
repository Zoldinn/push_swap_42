/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:55:32 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/20 19:20:56 by lefoffan         ###   ########.fr       */
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

int	get_dist(t_list *a, t_list *target)
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

	dist = get_dist(*a, target);
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
		if (node->content - closer->content > node->content - lst->content)
			closer = lst;
		lst = lst->next;
	}
	return (closer);
}

t_list	*get_smaller(t_list *lst, t_list *node)
{
	t_list	*tmp;

	tmp = lst;
	while (lst)
	{
		if (lst->content < node->content && tmp->content < lst->content)
			tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

void	ft_place_between(t_list *to_push, t_list **b)
{
	int	d_top;

	ft_printf("enculer de merde\n");
	d_top = get_dist(*b, get_smaller(*b, to_push));
	ft_printf("d_top = %d\n", d_top);
	while (d_top-- >= 0)
			ft_rotate(b, "rb\n");
	/* if (d_top < ft_lstsize(*b) / 2)
	{
		while (d_top--)
			ft_rotate(b, "rb\n");
	}
	else
	{
		while (d_top++ < ft_lstsize(*b))
			ft_rev_rotate(b, "rrb\n");
	} */
}

