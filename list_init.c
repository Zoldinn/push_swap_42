/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:10:18 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/10 13:59:32 by lefoffan         ###   ########.fr       */
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

int	ft_check(char **av, int ac)
{
	int		i;
	int		j;

	if (!av || ft_is_double(av))
		return (0);
	i = -1;
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

t_list	*ft_lst_init(char **av, int ac)
{
	t_list	*lst;
	char	**tab;

	lst = NULL;
	tab = ft_check(av, ac);
	if (!tab)
		return (NULL);
	while (*tab)
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_atoi(*tab)));
		tab++;
	}
	return (lst);
}
