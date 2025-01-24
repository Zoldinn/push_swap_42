/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:50:12 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/24 11:08:25 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	ft_swap(t_list **list, char *move);
void	ft_rotate(t_list **list, char *move);
void	ft_rev_rotate(t_list **list, char *move);
void	ft_push(t_list **a, t_list **b, char *move);
void	ft_db(void (*ft)(t_list**, char*), t_list **a, t_list **b, char *m);
t_list	*get_smaller(t_list *lst, t_list *node);
t_list	*ft_get_min(t_list *a);
t_list	*ft_get_max(t_list *a);
t_list	*ft_lst_init(char **strs);
void	ft_free_split(char **tab);
int		get_dist(t_list *start, t_list *end);
void	move(int size, int dist, t_list **lst, char *name_list);
void	move_both(int dist_a, int dist_b, t_list **a, t_list **b);
void	ft_sort(t_list **a, t_list **b);
void	lstprint(t_list *lst);

#endif