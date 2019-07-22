/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sort_vip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:28:21 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/22 12:39:32 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b3sort_sml_vip(t_push *p)
{
	ft_rb(p);
	ft_sb(p);
}

void	b3sort_slm_vip(t_push *p)
{
	ft_rb(p);
}

void	b3sort_mls_vip(t_push *p)
{
	ft_sb(p);
}

void	b3sort_msl_vip(t_push *p)
{
	ft_rrb(p);
}

void	b3sort_lsm_vip(t_push *p)
{
	ft_rrb(p);
	ft_sb(p);
}
