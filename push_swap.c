/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:57:21 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/06 16:45:06 by lefoffan         ###   ########.fr       */
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
	t_list	*list;

	list = NULL;
	ft_create_node(&list, 1);
	ft_print_list(list);
	ft_create_node(&list, 2);
	ft_print_list(list);
	ft_create_node(&list, 3);
	ft_print_list(list);
	ft_create_node(&list, 4);
	ft_print_list(list);
	printf("\n--- rotate --- \n");
	ft_rotate(&list);
	ft_print_list(list);
	printf("\n--- reverse rotate --- \n");
	ft_rev_rotate(&list);
	ft_print_list(list);
	printf("\n--- swap --- \n");
	ft_swap(&list);
	ft_print_list(list);

	ft_free_list(&list);
	return (0);
}