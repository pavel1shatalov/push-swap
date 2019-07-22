/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:43:00 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/21 16:00:44 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*init(int ac, char **av)
{
	t_push	*p;
	int		ind;

	if (!(p = (t_push *)malloc(sizeof(t_push))))
		return (NULL);
	p->lst1 = ft_newlst(ac - 1);
	p->s1 = ac - 1;
	p->stack1 = NULL;
	ind = 1;
	while (--ac)
		ft_pushback(&p->stack1, ft_atoi(av[ind++]));
	p->lst2 = NULL;
	p->s2 = 0;
	p->stack2 = NULL;
	p->sequence = NULL;
	return (p);
}

void	ft_print_sequence(t_swap *s)
{
	while (s)
	{
		ft_printf("%s\n", s->command);
		s = s->next;
	}
}

int		is_sorted(t_lst *lst, int len)
{
	int count;

	count = 1;
	while (lst && lst->next)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
		count++;
	}
	if (count < len)
		return (0);
	return (1);
}

int		is_top_sorted(t_push *p)
{
	int		top;
	t_lst	*cur;

	top = (p->lst1)->data;
	cur = p->stack1;
	while (--top)
	{
		if (cur->data > cur->next->data)
			return (0);
		cur = cur->next;
	}
	return (1);
}
