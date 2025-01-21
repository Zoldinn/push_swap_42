/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:22:23 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/21 14:24:44 by lefoffan         ###   ########.fr       */
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
	int		quarter;
	int		dist;

	cur = a;
	cheap = a;
	quarter = ft_lstsize(a) / 2;
	if (ft_lstsize(a) >= 60)
		quarter = ft_lstsize(a) / 4;
	else if (ft_lstsize(a) >= 20)
		quarter = ft_lstsize(a) / 3;
	while (cur)
	{
		dist = get_dist(a, cur);
		if (dist <= quarter || dist >= (ft_lstsize(a) - quarter))
		{
			if (cheap->content > cur->content)
				cheap = cur;
		}
		cur = cur->next;
	}
	return (cheap);
}

void	ft_sort_jsp2(t_list **a, t_list **b)
{
	t_list	*to_push;

	while (*a)
	{
		to_push = get_cheap(*a);
		move(ft_lstsize(*a), get_dist(*a, to_push), a, "a");
		if (ft_lstsize(*b) >= 2)
		{
			if (to_push->content < ft_get_min(*b)->content)
				move(ft_lstsize(*b), get_dist(*b, ft_get_min(*b)) + 1, b, "b");
			else if (to_push->content > ft_get_max(*b)->content)
				move(ft_lstsize(*b), get_dist(*b, ft_get_max(*b)), b, "b");
			else
				move(ft_lstsize(*b), get_dist(*b, get_smaller(*b, to_push)), b, "b");
		}
		ft_push(a, b, "pb\n");
	}
	while (ft_lstlast(*b) != ft_get_min(*b))
		ft_rev_rotate(b, "rrb\n");
	while (*b)
		ft_push(b, a, "pa\n");
}

void	ft_sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 3)
		ft_sort_three(a);
	else if (size <= 6)
		ft_sort_six(a, b);
	else
		ft_sort_jsp2(a, b);
}
