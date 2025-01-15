/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:57:21 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/15 16:54:16 by lefoffan         ###   ########.fr       */
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

void	pindex(t_list *a)
{
	t_list 	*tmp;

	tmp = a;
	while (tmp)
	{
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
	while (a)
	{
		ft_printf("%d ", a->index);
		a = a->next;
	}
	ft_printf("\n");
}
char	**get_arg(int ac, char **av)
{
	char	**split;
	int		i;

	if (ac == 2)
		split = ft_split(av[1], ' ');
	else
	{
		i = 0;
		split = malloc(sizeof(char *) * ac);
		while (i < ac - 1)
		{
			split[i] = ft_strdup(av[i + 1]);
			i++;
		}
		split[i] = NULL;
	}
	return (split);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**split;
	int		i;

	if (ac < 2)
		return (1);

	a = NULL;
	b = NULL;
	split = get_arg(ac, av);
	if (!split)
		return (1);
	a = ft_lst_init(split);
	if (!a)
		return (write(2, "Error\n", 6), 1);

	ft_sort(&a, &b);

	ft_lst_free(&a);
	if (b)
		ft_lst_free(&b);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	
	return (0);
}
