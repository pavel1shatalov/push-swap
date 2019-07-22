/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:34:08 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/22 12:56:35 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a2sort(t_push *p)
{
	if ((p->lst1)->data < 2)
		return ;
	if ((p->stack1)->data > (p->stack1)->next->data)
		ft_sa(p);
}

static int	a3sort_vip(t_push *p)
{
	int	a;
	int	b;
	int	c;

	a = p->stack1->data;
	b = p->stack1->next->data;
	c = p->stack1->next->next->data;
	(a < b) && (a < c) && (b > c) ? a3sort_slm_vip(p) : 0;
	(a < b) && (a > c) && (b > c) ? a3sort_mls_vip(p) : 0;
	(a > b) && (a < c) && (b < c) ? a3sort_msl_vip(p) : 0;
	(a > b) && (a > c) && (b < c) ? a3sort_lsm_vip(p) : 0;
	(a > b) && (a > c) && (b > c) ? a3sort_lms_vip(p) : 0;
	return (1);
}

static void	a3sort(t_push *p)
{
	int	a;
	int	b;
	int	c;

	if (!p->lst1->next && a3sort_vip(p))
		return ;
	a = p->stack1->data;
	b = p->stack1->next->data;
	c = p->stack1->next->next->data;
	(a < b) && (a < c) && (b > c) ? a3sort_slm(p) : 0;
	(a < b) && (a > c) && (b > c) ? a3sort_mls(p) : 0;
	(a > b) && (a < c) && (b < c) ? a3sort_msl(p) : 0;
	(a > b) && (a > c) && (b < c) ? a3sort_lsm(p) : 0;
	(a > b) && (a > c) && (b > c) ? a3sort_lms(p) : 0;
}

void		a_sort(t_push *p)
{
	if (p->lst1->data == 3)
		a3sort(p);
	else
		a2sort(p);
}
