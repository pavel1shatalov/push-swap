/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sort_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:49:11 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/18 21:18:31 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b3sort_sml(t_push *p)
{
	ft_sb(p);
	ft_rb(p);
	ft_sb(p);
	ft_rrb(p);
	ft_sb(p);
}

void	b3sort_slm(t_push *p)
{
	ft_sb(p);
	ft_rb(p);
	ft_sb(p);
	ft_rrb(p);
}

void	b3sort_mls(t_push *p)
{
	ft_sb(p);
}

void	b3sort_msl(t_push *p)
{
	ft_rb(p);
	ft_sb(p);
	ft_rrb(p);
	ft_sb(p);
}

void	b3sort_lsm(t_push *p)
{
	ft_rb(p);
	ft_sb(p);
	ft_rrb(p);
}
