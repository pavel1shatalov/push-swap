/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:36:51 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/16 20:25:39 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "checker.h"

typedef struct  s_push
{
    t_list		**lst1;     // keeps the number of elements in blocks
    t_list		**lst2;
    t_list      **stack1;   // keep the numbers in stacks
    t_list      **stack2;
}				t_push;

void    bubble_sort(t_list **lst, size_t size);
int     median(t_list *lst, size_t n);
int     partition(int *A, int left, int right);
void    a_partition(t_push *p);

#endif
