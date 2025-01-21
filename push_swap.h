/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:50:12 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/21 11:46:08 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

int		get_dist(t_list *start, t_list *end);
void	ft_db(void (*ft)(t_list**, char*), t_list **a, t_list **b, char *m);
void	ft_swap(t_list **list, char *move);
void	ft_rotate(t_list **list, char *move);
void	ft_rev_rotate(t_list **list, char *move);
void	ft_push(t_list **a, t_list **b, char *move);
void	ft_sort(t_list **a, t_list **b);
void	ft_move_to_top(t_list **a, t_list *target);
// void	ft_set_index(t_list **a);
t_list	*get_smaller(t_list *lst, t_list *node);
t_list	*ft_get_min(t_list *a);
t_list	*ft_get_max(t_list *a);
void	ft_place_between(t_list *to_push, t_list **b);
t_list	*ft_lst_init(char **av);
void	print(t_list *a, t_list *b);
void	move(int size, int dist, t_list **lst, char *name_list);

#endif