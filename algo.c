/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:22:23 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/16 19:20:41 by lefoffan         ###   ########.fr       */
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

void	ft_sort_twelve(t_list **a, t_list **b)
{
	while ((*a)->index < 6)
	{
		ft_move_to_top(a, ft_get_min(*a));
		ft_push(a, b, "pb\n");
	}
	ft_sort_six(a, b);
	while (*b)
		ft_push(b, a, "pa\n");
}

/* void	ft_sort_jsp(t_list **a, t_list **b)
{
	t_list	*cur;

	cur = *a;
	while (cur)
	{
		if (cur->content > cur->next->content)
			ft_push(a, b, "pb\n");
		else if (cur->content < ft_lstlast(cur)->content)
		{
			ft_rev_rotate(a, "rra\n");
			ft_push(a, b, "pb\n");
		}
		else if (cur->content)
	}
} */

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
	quarter = size / 4;
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

void	ft_sort_jsp2(t_list **a, t_list **b)
{
	t_list	*to_push;

	while (*a)
	{
		to_push = get_cheap(*a);
		ft_move_to_top(a, to_push);
		if () // chercher un nouveau plus petit si to push est pas a la suite dans b
		// if (*b && (*b)->next && (*b)->content < (*b)->next->content)
		// 	ft_rotate(b, "rb\n");
		ft_push(a, b, "pb\n");
	}
	while (*b)
		ft_push(b, a, "pa\n");
}


/* void	ft_sort_jsp3(t_list **a, t_list **b)
{
	while (*a)
	{
		ft_move_to_top(a, ft_get_min(*a));
		ft_push(a, b, "pb\n");
	}
	while (*b)
		ft_push(b, a, "pa\n");
} */

void	ft_sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 3)
		ft_sort_three(a);
	else
		ft_sort_jsp2(a, b);
}