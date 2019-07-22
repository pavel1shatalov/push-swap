/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:33:49 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/21 18:11:48 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
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
	if (read_instructions(p, av_mod, join))
		return (1);
	is_sorted(p->stack1, ac_mod - 1) ? ft_printf("OK\n") : ft_printf("KO\n");
	free_all(p, av_mod, join);
	return (0);
}
