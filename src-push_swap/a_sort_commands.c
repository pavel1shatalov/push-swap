/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sort_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 22:06:46 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/22 12:20:30 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a3sort_slm(t_push *p)
{
	ft_ra(p);
	ft_sa(p);
	ft_rra(p);
}

void	a3sort_mls(t_push *p)
{
	ft_ra(p);
	ft_sa(p);
	ft_rra(p);
	ft_sa(p);
}

void	a3sort_msl(t_push *p)
{
	ft_sa(p);
}

void	a3sort_lsm(t_push *p)
{
	ft_sa(p);
	ft_ra(p);
	ft_sa(p);
	ft_rra(p);
}

void	a3sort_lms(t_push *p)
{
	ft_sa(p);
	ft_ra(p);
	ft_sa(p);
	ft_rra(p);
	ft_sa(p);
}
