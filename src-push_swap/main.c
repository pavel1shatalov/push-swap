/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 16:40:14 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/18 23:40:10 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

int main(int ac, char **av)
{
	t_push	*p;

	p = init(ac, av);
	ft_printl(p);
	while (42)
	{
		a_partition(p);
		a_sort_basic(p);
		b_partition(p);
		b_sort_basic(p);
		if (is_sorted(*p->stack1) && p->s1 == (size_t)ac - 1)
			break;
	}
	ft_printl(p);
}
