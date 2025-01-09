/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:57:21 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/08 16:10:50 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list *a, t_list *b)
{
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
	ft_printf("\n\n");
}

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		int		i;
		int		*tab;
		t_list	*a;
		t_list	*b;

		a = NULL;
		b = NULL;
		i = 1;

		while (i < ac)
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(av[i++])));
		ft_print_list(a, b);
		ft_lst_free(&a);
		ft_lst_free(&b);
		return (0);
	}
	return (1);
}
