/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:29:17 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/20 19:38:34 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_count(t_push *p, int *count)
{
	ft_rotate(&p->stack1);
	ft_pushback_command(p, "ra");
	*count += 1;
}

void	ft_sa(t_push *p)
{
	ft_swap(&p->stack1);
	ft_pushback_command(p, "sa");
}

void	ft_sb(t_push *p)
{
	ft_swap(&p->stack2);
	ft_pushback_command(p, "sb");
}

void	ft_pa(t_push *p)
{
	ft_push(&p->stack1, &p->stack2);
	ft_pushback_command(p, "pa");
	p->s2 -= 1;
	p->s1 += 1;
	(p->lst2)->data -= 1;
	(p->lst1)->data += 1;
}

void	ft_pb(t_push *p)
{
	ft_push(&p->stack2, &p->stack1);
	ft_pushback_command(p, "pb");
	p->s1 -= 1;
	p->s2 += 1;
	(p->lst1)->data -= 1;
	(p->lst2)->data += 1;
}
