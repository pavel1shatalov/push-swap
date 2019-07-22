/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sort_vip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:13:10 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/22 12:31:29 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a3sort_slm_vip(t_push *p)
{
	ft_rra(p);
	ft_sa(p);
}

void	a3sort_mls_vip(t_push *p)
{
	ft_rra(p);
}

void	a3sort_msl_vip(t_push *p)
{
	ft_sa(p);
}

void	a3sort_lsm_vip(t_push *p)
{
	ft_ra(p);
}

void	a3sort_lms_vip(t_push *p)
{
	ft_ra(p);
	ft_sa(p);
}
