/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 22:06:46 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/18 23:40:40 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_lst *lst)
{
	while (lst && lst->next)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}




// This is kinda an optimization which I haven't finished yet
void	a_sort(t_push *p)
{
	if (((*p->stack1)->data > (*p->stack1)->next->data && \
		(*p->stack1)->next->data > (*p->stack1)->next->next->data) ||
		((*p->stack1)->data == (*p->stack1)->next->data && \
		(*p->stack1)->next->data > (*p->stack1)->next->next->data))
	{
		ft_swap(p->stack1);
		ft_push(p->stack2, p->stack1);
		ft_swap(p->stack1);
		ft_push(p->stack1, p->stack2);
		ft_swap(p->stack1);
	}
	else if (((*p->stack1)->data > (*p->stack1)->next->data && \
			(*p->stack1)->next->data < (*p->stack1)->next->next->data) ||
			((*p->stack1)->data > (*p->stack1)->next->data && \
			(*p->stack1)->next->data == (*p->stack1)->next->next->data))
	{
		ft_swap(p->stack1);
		ft_push(p->stack2, p->stack1);
		ft_swap(p->stack1);
		ft_push(p->stack1, p->stack2);
	}
	else if (((*p->stack1)->data < (*p->stack1)->next->data && \
			(*p->stack1)->next->data > (*p->stack1)->next->next->data) ||
			((*p->stack1)->data < (*p->stack1)->next->data && \
			(*p->stack1)->data == (*p->stack1)->next->next->data))
	{
		ft_push(p->stack2, p->stack1);
		ft_swap(p->stack1);
		ft_push(p->stack1, p->stack2);
	}
	else if ((*p->stack1)->data > (*p->stack1)->next->data && \
			(*p->stack1)->data == (*p->stack1)->next->next->data)
		ft_swap(p->stack1);
}

void	b_sort(t_push *p)
{
	if (p)
		return ;
}
