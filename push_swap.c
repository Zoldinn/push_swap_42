/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:57:21 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/07 16:53:37 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list *a, t_list *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d ", a->content);
			a = a->next;
		}
		else
			ft_printf(" ");
		if (b)
		{
			ft_printf("%d", b->content);
			b = b->next;
		}
		else
			ft_printf(" ");
		ft_printf("\n");
	}
	ft_printf("---\n");
}

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;

	ft_lstadd_back(&a, ft_lstnew(1));
	ft_lstadd_back(&a, ft_lstnew(2));
	ft_lstadd_back(&a, ft_lstnew(3));
	ft_lstadd_back(&a, ft_lstnew(4));
	ft_print_list(a, b);

	// rotate
	ft_rotate(&a, "ra");
	ft_print_list(a, b);

	// rev rotate
	ft_rev_rotate(&a, "rra");
	ft_print_list(a, b);

	// swap
	ft_swap(&a, "sa");
	ft_print_list(a, b);

	// push
	ft_push(&a, &b, "pb");
	ft_print_list(a, b);
	// push
	ft_push(&a, &b, "pb");
	ft_print_list(a, b);

	// push dans sens inverse
	ft_push(&b, &a, "pa");
	ft_print_list(a, b);

	ft_lst_free(&a);
	ft_lst_free(&b);
	return (0);
}