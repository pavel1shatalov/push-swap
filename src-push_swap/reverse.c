/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:27:57 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/20 19:46:58 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb_count(t_push *p, int *count)
{
	ft_rotate(&p->stack2);
	ft_pushback_command(p, "rb");
	*count += 1;
}

void	ft_ra(t_push *p)
{
	ft_rotate(&p->stack1);
	ft_pushback_command(p, "ra");
}

void	ft_rb(t_push *p)
{
	ft_rotate(&p->stack2);
	ft_pushback_command(p, "rb");
}

void	ft_rra(t_push *p)
{
	ft_reverse_rotate(&p->stack1);
	ft_pushback_command(p, "rra");
}

void	ft_rrb(t_push *p)
{
	ft_reverse_rotate(&p->stack2);
	ft_pushback_command(p, "rrb");
}
