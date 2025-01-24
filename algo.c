/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:22:23 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/22 15:34:49 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **a)
{
	int	i;

	i = 0;
	while (i++ < 3)
	{
		if ((*a)->content > (*a)->next->content)
			ft_swap(a, "sa\n");
		if ((*a)->content > ft_lstlast(*a)->content)
			ft_rev_rotate(a, "rra\n");
		if ((*a)->next->content > ft_lstlast(*a)->content)
			ft_rev_rotate(a, "rra\n");
	}
}

void	ft_sort_six(t_list **a, t_list **b)
{
	int	chunk;
	int	i;

	chunk = ft_lstsize(*a) - 3;
	i = 0;
	while (i++ < chunk)
	{
		move(ft_lstsize(*a), get_dist(*a, ft_get_min(*a)), a, "a");
		ft_push(a, b, "pb\n");
	}
	ft_sort_three(a);
	while (chunk--)
		ft_push(b, a, "pa\n");
}

t_list	*get_cheap(t_list *a)
{
	t_list	*cheap;
	t_list	*cur;
	int		chunk;
	int		dist;

	cur = a;
	cheap = a;
	chunk = ft_lstsize(a) / 2;
	if (ft_lstsize(a) >= 100)
		chunk = ft_lstsize(a) / 20;
	else if (ft_lstsize(a) >= 20)
		chunk = 5;
	while (cur)
	{
		dist = get_dist(a, cur);
		if (dist <= chunk || dist >= (ft_lstsize(a) - chunk))
		{
			if (cheap->content > cur->content)
				cheap = cur;
		}
		cur = cur->next;
	}
	return (cheap);
}

int	get_dist_b(t_list **b, t_list *to_push)
{
	if (to_push->content < ft_get_min(*b)->content)
		return (get_dist(*b, ft_get_min(*b)) + 1);
	else if (to_push->content > ft_get_max(*b)->content)
		return (get_dist(*b, ft_get_max(*b)));
	else
		return (get_dist(*b, get_smaller(*b, to_push)));
}

void	ft_sort(t_list **a, t_list **b)
{
	t_list	*to_push;
	int		dist_a;
	int		dist_b;

	if (ft_lstsize(*a) <= 3)
		ft_sort_three(a);
	else if (ft_lstsize(*a) <= 6)
		ft_sort_six(a, b);
	else
	{
		while (*a && ft_lstsize(*a) > 6)
		{
			to_push = get_cheap(*a);
			dist_a = get_dist(*a, to_push);
			if (ft_lstsize(*b) >= 2)
				dist_b = get_dist_b(b, to_push);
			move_both(dist_a, dist_b, a, b);
			ft_push(a, b, "pb\n");
		}
		ft_sort_six(a, b);
		while (ft_lstlast(*b) != ft_get_min(*b))
			ft_rev_rotate(b, "rrb\n");
		while (*b)
			ft_push(b, a, "pa\n");
	}
}
