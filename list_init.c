/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:10:18 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/20 10:30:24 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_too_large(char *str)
{
	const char	*limit;
	size_t		len;
	int			i;

	if (!str)
		return (-1);
	if (*str == '-')
		limit = "2147483648";
	else
		limit = "2147483647";
	len = ft_strlen(str);
	if (len > 10)
		return (1);
	else if (len < 10)
		return (0);
	else
	{
		i = -1;
		while (str[++i])
		{
			if (str[i] > limit[i])
				return (1);
		}
		return (0);
	}
}

int	ft_is_double(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = i;
		while (av[++j])
		{
			if (ft_strncmp(av[j], av[i], 11) == 0)
				return (1);
		}
	}
	return (0);
}

int	ft_check(char **av)
{
	int		i;
	int		j;

	if (ft_is_double(av))
		return (0);
	i = 0;
	while (av[++i])
	{
		if (ft_is_too_large(av[i]))
			return (0);
		j = 0;
		while (av[i][j])
		{
			if (((av[i][j] == '-' || av[i][j] == '+') && av[i][j + 1]))
				j++;
			else if (!ft_isdigit((int) av[i][j++]))
				return (0);
		}
	}
	return (1);
}

t_list	*ft_lst_init(char **av)
{
	t_list	*lst;
	int		i;

	lst = NULL;
	if (!ft_check(av))
		return (NULL);
	i = 0;
	while (av[i])
		ft_lstadd_back(&lst, ft_lstnew(ft_atoi(av[i++])));
	// ft_set_index(&lst);
	return (lst);
}

/* void	ft_set_index(t_list **a)
{
	int		smaller;
	t_list	*cur;
	t_list	*tmp;

	cur = *a;
	while (cur)
	{
		smaller = 0;
		tmp = *a;
		while (tmp)
		{
			if (cur->content > tmp->content)
				smaller += 1;
			tmp = tmp->next;
		}
		cur->index = smaller;
		cur = cur->next;
	}
} */