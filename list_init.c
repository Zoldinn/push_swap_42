/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:10:18 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/24 11:12:07 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_check(char **strs)
{
	int		i;
	int		j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		if (strs[i][0] == '-' || strs[i][0] == '+')
			j++;
		if (!ft_isdigit(strs[i][j]))
			return (0);
		while (strs[i][j])
		{
			if (!ft_isdigit((int) strs[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_double(t_list *lst)
{
	t_list	*tmp;

	while (lst->next)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->content == tmp->content)
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}

t_list	*ft_lst_init(char **strs)
{
	long int	nb;
	t_list		*lst;
	t_list		*new;
	int			i;

	lst = NULL;
	if (!ft_check(strs))
		return (NULL);
	i = 0;
	while (strs[i])
	{
		nb = ft_atoi(strs[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (ft_lst_free(&lst), NULL);
		new = ft_lstnew(ft_atoi(strs[i++]));
		if (!new)
			return (ft_lst_free(&lst), free(new), NULL);
		ft_lstadd_back(&lst, new);
	}
	if (ft_is_double(lst))
		return (ft_lst_free(&lst), NULL);
	return (lst);
}
