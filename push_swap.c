/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:57:21 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/08 11:52:00 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	ft_print_list(t_list *a, t_list *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d ", a->content);
			a = a->next;
		}
		if (b)
		{
			ft_printf("%d", b->content);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("---\n");
} */

void	ft_print_list(t_list *a, t_list *b)
{
	t_list	*tmp_a = a;
	t_list	*tmp_b = b;
	int		size_a = 0;
	int		size_b = 0;
	int		i;

	// Calcul de la taille des deux piles
	while (tmp_a)
	{
		size_a++;
		tmp_a = tmp_a->next;
	}
	while (tmp_b)
	{
		size_b++;
		tmp_b = tmp_b->next;
	}

	// Affichage des piles de bas en haut
	while (size_a > 0 || size_b > 0)
	{
		tmp_a = a;
		tmp_b = b;

		// Aller jusqu'à l'élément à afficher
		i = 0;
		while (i < size_a - 1 && tmp_a)
		{
			tmp_a = tmp_a->next;
			i++;
		}
		i = 0;
		while (i < size_b - 1 && tmp_b)
		{
			tmp_b = tmp_b->next;
			i++;
		}

		// Afficher l'élément correspondant, ou rien si la pile est vide
		if (size_a > 0 && tmp_a)
			ft_printf("%d ", tmp_a->content);
		else
			ft_printf("  "); // Espace pour aligner avec la pile b
		if (size_b > 0 && tmp_b)
			ft_printf("%d", tmp_b->content);
		ft_printf("\n");

		size_a--;
		size_b--;
	}

	ft_printf("---\n");
	ft_printf("a b\n----------\n");
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

	// rrr
	ft_db(&ft_rev_rotate, &a, &b, "rrr");
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