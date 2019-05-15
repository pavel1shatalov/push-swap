/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 04:05:31 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/15 20:37:34 by ggerhold         ###   ########.fr       */
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
    char	is_sorted;
    size_t  ind;
    size_t  len;

	is_sorted = 1;
    len = n;
    while (--n)
    {
		is_sorted = 1;
        ind = 0;
        while (ind < n)
        {
            if (*(int *)(*lst)->content > *(int *)(*lst)->next->content)
            {
                ft_swap(lst);
				is_sorted = 0;
                ft_printf("sa\n");
            }
            ft_reverse_rotate(lst);
            ft_printf("rra\n");
            ind++;
        }
		if (is_sorted)
			break;
        bubble_skip(lst, ind, len);
    }
}

void    bubble_sort_alternative(t_list **lst, size_t n)
{
    // it's easy to implement using two stacks
    return ;
}
