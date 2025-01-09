/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:10:18 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/09 11:57:31 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

/* long int	ft_long_atoi(char *str)
{
	long int	res;
	int			sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (*str * 10) + '0';
		str++;
	}
	return (res * sign);
}

int	ft_is_too_large(char **av)
{
	long int	nb;
	int			i;

	i = 0;
	while (av[++i])
	{
		nb = ft_long_atoi(av[i]);
		if (nb <= INT_MIN || nb >= INT_MAX)
			return (1);
	}
	return (0);
} */

int	ft_is_too_large(char *str)
{
	const char	*limit;
	int			len;

	if (*str == '-')
		limit = "2147483648";
	else
		limit = "2147483647";
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
			if (ft_strnstr(av[j], av[i], ft_strlen(av[i])));
				return (1);
		}
	}
	return (0);
}

// cherche la taille du tableau final en faisant count word de chaque av[i]
// malloc a cette taille
// ft_split a chaque av[i] et l'ajoute au tableau final
char	**ft_get_args(char **av)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (av[++i])
	{
		count += ft_count_word(av[i], ' ')
	}
}

// parcours mes args, verifs
// si verif ok, split la string
// parcours le tableau de tableau, le transforme en 

t_list	*ft_init_list(char **av)
{

}