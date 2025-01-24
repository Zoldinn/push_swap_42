/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:01:26 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/23 16:02:26 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_free(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
		return ;
	tmp = *lst;
	while ((*lst)->next)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	free(tmp);
}
