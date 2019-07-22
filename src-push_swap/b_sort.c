/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:36:39 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/22 12:56:41 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	b2sort(t_push *p)
{
	if ((p->lst2)->data == 1)
	{
		ft_pushfront(&p->lst1, 0);
		ft_pa(p);
		ft_popfront(&p->lst2);
		return ;
	}
	if ((p->stack2)->data < (p->stack2)->next->data)
		ft_sb(p);
	ft_pushfront(&p->lst1, 0);
	ft_pa(p);
	ft_pa(p);
	ft_popfront(&p->lst2);
}

static int	b3sort_vip(t_push *p)
{
	int	a;
	int	b;
	int	c;

	a = p->stack2->data;
	b = p->stack2->next->data;
	c = p->stack2->next->next->data;
	(a < b) && (a < c) && (b < c) ? b3sort_sml_vip(p) : 0;
	(a < b) && (a < c) && (b > c) ? b3sort_slm_vip(p) : 0;
	(a < b) && (a > c) && (b > c) ? b3sort_mls_vip(p) : 0;
	(a > b) && (a < c) && (b < c) ? b3sort_msl_vip(p) : 0;
	(a > b) && (a > c) && (b < c) ? b3sort_lsm_vip(p) : 0;
	ft_pushfront(&p->lst1, 0);
	ft_pa(p);
	ft_pa(p);
	ft_pa(p);
	ft_popfront(&p->lst2);
	return (1);
}

static void	b3sort(t_push *p)
{
	int	a;
	int	b;
	int	c;

	if (!p->lst2->next && b3sort_vip(p))
		return ;
	a = p->stack2->data;
	b = p->stack2->next->data;
	c = p->stack2->next->next->data;
	(a < b) && (a < c) && (b < c) ? b3sort_sml(p) : 0;
	(a < b) && (a < c) && (b > c) ? b3sort_slm(p) : 0;
	(a < b) && (a > c) && (b > c) ? b3sort_mls(p) : 0;
	(a > b) && (a < c) && (b < c) ? b3sort_msl(p) : 0;
	(a > b) && (a > c) && (b < c) ? b3sort_lsm(p) : 0;
	ft_pushfront(&p->lst1, 0);
	ft_pa(p);
	ft_pa(p);
	ft_pa(p);
	ft_popfront(&p->lst2);
}

void		b_sort(t_push *p)
{
	if (!(p->lst2))
		return ;
	if (!(is_top_sorted(p)))
		return ;
	if (p->lst2->data == 3)
		b3sort(p);
	else
		b2sort(p);
}
