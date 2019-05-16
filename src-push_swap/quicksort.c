/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:32:51 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/16 20:57:18 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    a_partition(t_push *p)
{
	int m;
	int n;

	while (*(int *)((*p->lst1)->content) > 3)
	{
		n = *(int *)((*p->lst1)->content);
		m = median(*p->stack1, n);
		ft_printf("median is %d\n", m);
		while (n-- && *(int *)((*p->lst1)->content) > 2)
		{
			// I should support numbers count in both stacks using a perfect structure
			// For now I don't care about the second list at all !
			if (*(int *)((*p->stack1)->content) > m)
				ft_rotate(p->stack1);
			else
			{
				ft_push(p->stack2, p->stack1);
				*(int *)((*p->lst1)->content) -= 1;
			}
			ft_printl(*p->stack1, 1);
			ft_printf("_-_\n");
			ft_printl(*p->stack2, 2);
			ft_printf("_____________\n");
		}
	}
}
