/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:22:23 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/19 00:27:51 by lefoffan         ###   ########.fr       */
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
		ft_move_to_top(a, ft_get_min(*a));
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
	int		size;
	int		quarter;
	int		dist;

	cur = a;
	cheap = a;
	size = ft_lstsize(a);
	quarter = size / 4; // par 2, ca trie bien, mais en trop de coups..
	while (cur)
	{
		dist = ft_get_dist(a, cur);
		if (dist <= quarter || dist >= (size - quarter))
		{
			if (cheap->content > cur->content)
				cheap = cur;
		}
		cur = cur->next;
	}
	return (cheap);
}

void	ft_sort_b(t_list **b)
{
	t_list	*top;

	if (!*b || !(*b)->next)
		return ;
	top = *b;
	if (top == ft_get_min(*b) && top != ft_lstlast(*b))
		ft_rotate(b, "rb\n");
	if (top != ft_get_max(*b) && top->next == ft_get_max(*b))
		ft_swap(b, "sb\n");
	/*if (top->index < ft_get_max(*b)->index
		&& top->index > ft_get_min(*b)->index)
	{
		
	}*/
}

void	ft_sort_jsp2(t_list **a, t_list **b)
{
	t_list	*to_push;

	while (*a)
	{
		to_push = get_cheap(*a);
		ft_move_to_top(a, to_push);
		ft_push(a, b, "pb\n");
		ft_sort_b(b);
	}
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
