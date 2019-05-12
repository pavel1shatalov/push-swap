/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 04:05:31 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/12 05:31:32 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    bubble_skip(t_list **lst, size_t ind, size_t len)
{
    if (ind > len / 2)
    {
        while (ind < len)
        {
            ft_reverse_rotate(lst);
            ft_printf("rra\n");
            ind++;
        }
    }
    else
    {
        while (ind > 0)
        {
            ft_rotate(lst);
            ft_printf("ra\n");
            ind--;
        }
    }
}

void    bubble_sort(t_list **lst, size_t n)
{
    size_t  ind;
    size_t  len;

    len = n;
    while (--n)
    {
        ind = 0;
        while (ind < n)
        {
            if (*(int *)(*lst)->content > *(int *)(*lst)->next->content)
            {
                ft_swap(lst);
                ft_printf("sa\n");
            }
            ft_reverse_rotate(lst);
            ft_printf("rra\n");
            ind++;
        }
        bubble_skip(lst, ind, len);
    }
}
