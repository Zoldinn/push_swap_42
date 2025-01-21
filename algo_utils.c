/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:55:32 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/21 14:21:09 by lefoffan         ###   ########.fr       */
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

int	get_dist(t_list *start, t_list *end)
{
	int	dist;

	dist = 0;
	while (start && start != end)
	{
		dist += 1;
		start = start->next;
	}
	return (dist);
}

t_list	*get_smaller(t_list *lst, t_list *to_push)
{
	t_list	*smaller;

	smaller = NULL;
	while (lst)
	{
		if (lst->content < to_push->content
			&& (!smaller || smaller->content < lst->content))
			smaller = lst;
		lst = lst->next;
	}
	return (smaller);
}

void	move(int size, int dist, t_list **lst, char *name_list)
{
	if (dist < size / 2)
	{
		while (dist--)
		{
			if (*name_list == 'a')
				ft_rotate(lst, "ra\n");
			else
				ft_rotate(lst,"rb\n");
		}
	}
	else
	{
		while (dist++ < size)
		{
			if (*name_list == 'a')
				ft_rev_rotate(lst, "rra\n");
			else
				ft_rev_rotate(lst,"rrb\n");
		}
	}
}
