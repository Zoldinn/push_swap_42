/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:57:21 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/24 11:11:23 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_already_sort(t_list *lst)
{
	while (lst)
	{
		if (lst->next && lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

char	**get_arg(int ac, char **av)
{
	char	**split;
	int		i;

	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split)
			return (ft_free_split(split), NULL);
	}
	else
	{
		i = 1;
		split = malloc(sizeof(char *) * ac);
		if (!split)
			return (NULL);
		while (i < ac)
		{
			split[i - 1] = ft_strdup(av[i]);
			if (!split[i - 1])
				return (ft_free_split(split), NULL);
			i++;
		}
		split[i - 1] = NULL;
	}
	return (split);
}

void	lstprint(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d ", lst->content);
		lst = lst->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**split;

	if (ac < 2)
		return (1);
	a = NULL;
	b = NULL;
	split = get_arg(ac, av);
	if (!split)
		return (write(2, "Error\n", 6), 1);
	a = ft_lst_init(split);
	if (!a)
		return (ft_free_split(split), write(2, "Error\n", 6), 1);
	if (!is_already_sort(a))
		ft_sort(&a, &b);
	ft_free_split(split);
	ft_lst_free(&a);
	ft_lst_free(&b);
	return (0);
}
