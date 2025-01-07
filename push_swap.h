/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:50:12 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/07 11:46:31 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct		s_list
{
	int				nb;
	struct s_list	*next;
}					t_list;

t_list	*ft_lst_last(t_list *lst);
void	ft_lst_free(t_list **list);
void	ft_create_node(t_list **list, int nb);
void	ft_swap(t_list **list, char *move);
void	ft_rotate(t_list **list, char *move);
void	ft_rev_rotate(t_list **list, char *move);
void	ft_push(t_list **a, t_list **b, char *move);

#endif