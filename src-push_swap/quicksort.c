/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:32:51 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/18 23:42:05 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    a_partition(t_push *p)
{
	int m;
	int n;

	while ((*p->lst1)->data > 2)
	{
		n = (*p->lst1)->data;
		m = median(*p->stack1, (*p->lst1)->data);
		ft_pushfront(p->lst2, 0);
		while (n-- && (*p->lst1)->data > 2)
		{
			if ((*p->stack1)->data > m)
				ft_rotate(p->stack1);
			else
			{
				ft_push(p->stack2, p->stack1);
				p->s1 -= 1;
				p->s2 += 1;
				(*p->lst1)->data -= 1;
				if (!(*p->lst1)->data)
					ft_popfront(p->lst1);
				(*p->lst2)->data += 1;
			}
			ft_printl(p);
		}
	}
}

void    b_partition(t_push *p)
{
	int m;
	int n;

	while ((*p->lst2)->data > 2)
	{
		n = (*p->lst2)->data;
		m = median(*p->stack2, (*p->lst2)->data);
		ft_pushfront(p->lst1, 0);
		while (n-- && (*p->lst2)->data > 2)
		{
			if ((*p->stack2)->data < m)
				ft_rotate(p->stack2);
			else
			{
				ft_push(p->stack1, p->stack2);
				p->s2 -= 1;
				p->s1 += 1;
				(*p->lst2)->data -= 1;
				if (!(*p->lst2)->data)
					ft_popfront(p->lst2);
				(*p->lst1)->data += 1;
			}
			ft_printl(p);
		}
	}
}

void	a_sort_basic(t_push *p)
{
	if ((*p->lst1)->data < 2)
		return ;
	if ((*p->stack1)->data > (*p->stack1)->next->data)
		ft_swap(p->stack1);
}

void	b_sort_basic(t_push *p)
{
	if ((*p->lst2)->data < 2)
	{
		ft_push(p->stack1, p->stack2);
		ft_popfront(p->lst2);
		p->s1 += 1;
		p->s2 -= 1;
		return ;
	}
	if ((*p->stack2)->data < (*p->stack2)->next->data)
		ft_swap(p->stack2);
	ft_push(p->stack1, p->stack2);
	ft_push(p->stack1, p->stack2);
	ft_popfront(p->lst2);
	p->s1 += 2;
	p->s2 -= 2;
}
