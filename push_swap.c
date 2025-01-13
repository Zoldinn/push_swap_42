/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:57:21 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/13 17:59:15 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list *a, t_list *b)
{
	ft_printf("\n----------\n");
	ft_printf("a | ");
	while (a)
	{
		ft_printf("%d, ", a->content);
		a = a->next;
	}
	ft_printf("\nb | ");
	while (b)
	{
		ft_printf("%d, ", b->content);
		b = b->next;
	}
	ft_printf("\n----------\n");
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		t_list	*a;
		t_list	*b;

		a = NULL;
		b = NULL;

		a = ft_lst_init(av);
		if (!a)
			return (write(2, "Error\n", 6), 1);
		ft_print_list(a, b);
		ft_sort(&a, &b);
		ft_print_list(a, b);
		ft_lst_free(&a);
		if (b)
			ft_lst_free(&b);
		return (0);
	}
	return (1);
}
