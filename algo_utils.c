/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:55:32 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/13 17:57:30 by lefoffan         ###   ########.fr       */
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

void	ft_move_min_to_top(t_list **a)
{
	t_list	*min;
	int		dist;
	int		size;

	min = ft_get_min(*a);
	dist = ft_get_dist(*a, min);
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