/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:35:49 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/21 17:42:46 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_lst(t_lst **lst)
{
	t_lst	*cur;
	t_lst	*tmp;

	if (!lst || !(*lst))
		return ;
	cur = *lst;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	*lst = NULL;
}

static void	free_sequence(t_swap **s)
{
	t_swap	*cur;
	t_swap	*tmp;

	if (!s || !(*s))
		return ;
	cur = *s;
	while (cur)
	{
		tmp = cur->next;
		free(cur->command);
		cur->command = NULL;
		free(cur);
		cur = tmp;
	}
	*s = NULL;
}

void		free_error(char **split, char *join)
{
	char **cur;

	cur = split;
	while (*cur)
		ft_strdel(cur++);
	free(split);
	split = NULL;
	ft_strdel(&join);
}

void		free_all(t_push *p, char **split, char *join)
{
	free_error(split, join);
	free_lst(&p->stack1);
	free_lst(&p->stack2);
	free_lst(&p->lst1);
	free_lst(&p->lst2);
	free_sequence(&p->sequence);
	free(p);
	p = NULL;
}
