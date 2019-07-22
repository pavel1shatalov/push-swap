/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:32:51 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/22 12:12:15 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_partition_vip(t_push *p)
{
	int m;
	int n;

	while ((p->lst1)->data > 3 && !(is_top_sorted(p)))
	{
		m = median(p->stack1, (p->lst1)->data);
		n = (p->lst1)->data;
		ft_pushfront(&p->lst2, 0);
		while (n--)
			if ((p->stack1)->data > m)
				ft_ra(p);
			else
				ft_pb(p);
	}
}

static void	b_partition_vip(t_push *p)
{
	int m;
	int n;

	while ((p->lst2)->data > 3 && is_top_sorted(p))
	{
		m = median(p->stack2, (p->lst2)->data);
		n = (p->lst2)->data;
		ft_pushfront(&p->lst1, 0);
		while (n--)
			if ((p->stack2)->data <= m)
				ft_rb(p);
			else
				ft_pa(p);
	}
}

void		a_partition(t_push *p)
{
	int m;
	int n;
	int	count;

	if (!p->lst1->next)
		a_partition_vip(p);
	while ((p->lst1)->data > 3 && !(is_top_sorted(p)))
	{
		count = 0;
		m = median(p->stack1, (p->lst1)->data);
		n = (p->lst1)->data;
		ft_pushfront(&p->lst2, 0);
		while (n--)
			if ((p->stack1)->data > m)
				ft_ra_count(p, &count);
			else
				ft_pb(p);
		while (count-- > 0)
			ft_rra(p);
	}
}

void		b_partition(t_push *p)
{
	int m;
	int n;
	int count;

	if (p->lst2 && !p->lst2->next)
		b_partition_vip(p);
	while ((p->lst2) && (p->lst2)->data > 3 && is_top_sorted(p))
	{
		count = 0;
		m = median(p->stack2, (p->lst2)->data);
		n = (p->lst2)->data;
		ft_pushfront(&p->lst1, 0);
		while (n--)
			if ((p->stack2)->data <= m)
				ft_rb_count(p, &count);
			else
				ft_pa(p);
		while (count-- > 0)
			ft_rrb(p);
	}
}
