/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:34:14 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/21 18:29:07 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_excess(t_swap *s)
{
	if ((!ft_strcmp(s->next->command, "ra") &&
	!ft_strcmp(s->next->next->command, "rra")) || \
	(!ft_strcmp(s->next->command, "rra") && \
	!ft_strcmp(s->next->next->command, "ra")) || \
	(!ft_strcmp(s->next->command, "rb") && \
	!ft_strcmp(s->next->next->command, "rrb")) || \
	(!ft_strcmp(s->next->command, "rrb") && \
	!ft_strcmp(s->next->next->command, "rb")))
		return (1);
	else
		return (0);
}

static int		merge_reverse(t_swap *s)
{
	t_swap	*tmp;
	int		flag;

	flag = 0;
	while (s && s->next && s->next->next)
		if (is_excess(s))
		{
			tmp = s->next->next->next;
			free(s->next->next->command);
			s->next->next->command = NULL;
			free(s->next->next);
			s->next->next = NULL;
			free(s->next->command);
			s->next->command = NULL;
			free(s->next);
			s->next = tmp;
			flag = 1;
		}
		else
			s = s->next;
	return (flag);
}

static void		merge_swap(t_swap *s)
{
	t_swap	*tmp;

	while (s && s->next)
	{
		if ((!ft_strcmp(s->command, "sa") && \
		!ft_strcmp(s->next->command, "sb")))
		{
			tmp = s->next->next;
			free(s->next->command);
			s->next->command = NULL;
			free(s->next);
			s->next = NULL;
			s->command[1] = 's';
			s->next = tmp;
		}
		s = s->next;
	}
}

void			merge(t_push *p)
{
	while (merge_reverse(p->sequence))
		;
	merge_swap(p->sequence);
}
