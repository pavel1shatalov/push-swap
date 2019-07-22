/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 14:29:03 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/21 16:02:14 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_swap	*ft_newcommand(char *str)
{
	t_swap	*s;

	if (!(s = (t_swap *)malloc(sizeof(t_swap))))
		exit(1);
	if (!(s->command = ft_strnew(ft_strlen(str))))
		exit(1);
	s->command = ft_strcpy(s->command, str);
	s->next = NULL;
	return (s);
}

void			ft_pushback_command(t_push *p, char *str)
{
	t_swap	**s;
	t_swap	*cur;

	if (!p)
		return ;
	s = &p->sequence;
	if (*s)
	{
		cur = *s;
		while (cur->next)
			cur = cur->next;
		cur->next = ft_newcommand(str);
	}
	else
		*s = ft_newcommand(str);
}
