/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefoffan <lefoffan@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:50:12 by lefoffan          #+#    #+#             */
/*   Updated: 2025/01/10 13:57:09 by lefoffan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	ft_swap(t_list **list, char *move);
void	ft_rotate(t_list **list, char *move);
void	ft_rev_rotate(t_list **list, char *move);
void	ft_push(t_list **a, t_list **b, char *move);
void	ft_db(void (*ft)(t_list**, char*), t_list **a, t_list **b, char *m);
t_list	*ft_lst_init(char **av, int ac);

#endif