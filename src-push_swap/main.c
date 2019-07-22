/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:40:14 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/21 19:19:48 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	magic(t_push *p)
{
	a_partition(p);
	a_sort(p);
	b_partition(p);
	b_sort(p);
}

int			main(int ac, char **av)
{
	t_push	*p;
	char	*join;
	char	**av_mod;
	int		ac_mod;

	join = ft_join(ac, av);
	av_mod = ft_strsplit(join, ' ');
	if (!(join) || !(av_mod))
		return (1);
	ac_mod = ft_splitlen(av_mod);
	if (error(ac_mod, av_mod, join))
		return (1);
	if (!(p = init(ac_mod, av_mod)))
		return (1);
	while (!(is_sorted(p->stack1, ac_mod - 1)))
		magic(p);
	merge(p);
	ft_print_sequence(p->sequence);
	free_all(p, av_mod, join);
	return (0);
}
