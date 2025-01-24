/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:25:32 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/22 15:35:41 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(int size, int dist, t_list **lst, char *name_list)
{
	if (dist < size / 2)
	{
		while (dist--)
		{
			if (*name_list == 'a')
				ft_rotate(lst, "ra\n");
			else
				ft_rotate(lst, "rb\n");
		}
	}
	else
	{
		while (dist++ < size)
		{
			if (*name_list == 'a')
				ft_rev_rotate(lst, "rra\n");
			else
				ft_rev_rotate(lst, "rrb\n");
		}
	}
}

void	ft_move_adjust(int dist_a, int dist_b, t_list **a, t_list **b)
{
	if (dist_a < ft_lstsize(*a) / 2)
	{
		while (dist_a-- > 0)
			ft_rotate(a, "ra\n");
	}
	else
	{
		while (dist_a++ < ft_lstsize(*a))
			ft_rev_rotate(a, "rra\n");
	}
	if (dist_b < ft_lstsize(*b) / 2)
	{
		while (dist_b-- > 0)
			ft_rotate(b, "rb\n");
	}
	else
	{
		while (dist_b++ < ft_lstsize(*b))
			ft_rev_rotate(b, "rrb\n");
	}
}

void	move_both(int dist_a, int dist_b, t_list **a, t_list **b)
{
	if (dist_a < ft_lstsize(*a) / 2 && dist_b < ft_lstsize(*b) / 2)
	{
		while (dist_a > 0 && dist_b > 0)
		{
			ft_db(&ft_rotate, a, b, "rr\n");
			dist_a--;
			dist_b--;
		}
	}
	else if (dist_a >= ft_lstsize(*a) / 2 && dist_b >= ft_lstsize(*b) / 2)
	{
		while (dist_a < ft_lstsize(*a) && dist_b < ft_lstsize(*b))
		{
			ft_db(&ft_rev_rotate, a, b, "rrr\n");
			dist_a++;
			dist_b++;
		}
	}
	ft_move_adjust(dist_a, dist_b, a, b);
}
