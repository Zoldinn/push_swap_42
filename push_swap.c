/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:57:21 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/07 11:00:05 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list *list)
{
	while (list)
	{
		printf("%d\n", list->nb);
		list = list->next;
	}
	printf("---\n");
}

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;

	ft_create_node(&a, 1);
	ft_create_node(&a, 4);
	ft_create_node(&a, 2);
	ft_create_node(&a, 3);
	ft_print_list(a);

	printf("\n--- rotate --- \n");
	ft_rotate(&a);
	ft_print_list(a);

	printf("\n--- reverse rotate --- \n");
	ft_rev_rotate(&a);
	ft_print_list(a);

	printf("\n--- swap --- \n");
	ft_swap(&a);
	ft_print_list(a);

	printf("\n--- push --- \n");
	ft_push(&a, &b);
	ft_print_list(a);
	ft_print_list(b);

	printf("\n--- push --- \n");
	ft_push(&a, &b);
	ft_print_list(a);
	ft_print_list(b);

	ft_free_list(&a);
	ft_free_list(&b);
	return (0);
}