/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:00:54 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/22 15:05:23 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	read_push_swap(t_push *p, char *command)
{
	if (!ft_strcmp("sa", command))
		ft_swap(&p->stack1);
	else if (!ft_strcmp("sb", command))
		ft_swap(&p->stack2);
	else if (!ft_strcmp("ss", command))
	{
		ft_swap(&p->stack1);
		ft_swap(&p->stack2);
	}
	else if (!ft_strcmp("pa", command))
		ft_push(&p->stack1, &p->stack2);
	else if (!ft_strcmp("pb", command))
		ft_push(&p->stack2, &p->stack1);
	else
		return (0);
	return (1);
}

static int	read_rotate(t_push *p, char *command)
{
	if (!ft_strcmp("ra", command))
		ft_rotate(&p->stack1);
	else if (!ft_strcmp("rb", command))
		ft_rotate(&p->stack2);
	else if (!ft_strcmp("rr", command))
	{
		ft_rotate(&p->stack1);
		ft_rotate(&p->stack2);
	}
	else if (!ft_strcmp("rra", command))
		ft_reverse_rotate(&p->stack1);
	else if (!ft_strcmp("rrb", command))
		ft_reverse_rotate(&p->stack2);
	else if (!ft_strcmp("rrr", command))
	{
		ft_reverse_rotate(&p->stack2);
		ft_reverse_rotate(&p->stack2);
	}
	else
		return (0);
	return (1);
}

int			read_instructions(t_push *p, char **av, char *join)
{
	char	*command;

	while (get_next_line(0, &command))
		if (!(read_push_swap(p, command)) && !(read_rotate(p, command)))
		{
			write(1, "Error\n", 6);
			ft_strdel(&command);
			free_all(p, av, join);
			return (1);
		}
		else
			ft_strdel(&command);
	ft_strdel(&command);
	return (0);
}
