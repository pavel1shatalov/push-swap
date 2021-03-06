/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:26:49 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/21 18:14:07 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(t_lst **stack)
{
	int	tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = tmp;
	}
}

void	ft_rotate(t_lst **stack)
{
	t_lst	*cur;
	int		tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	cur = *stack;
	tmp = (*stack)->data;
	while (cur->next)
		cur = cur->next;
	cur->next = ft_newlst(tmp);
	ft_popfront(stack);
}

void	ft_reverse_rotate(t_lst **stack)
{
	t_lst	*cur;
	t_lst	*tmp;
	int		n;

	if (!(*stack) || !(*stack)->next)
		return ;
	cur = *stack;
	while (cur->next->next)
		cur = cur->next;
	n = cur->next->data;
	tmp = cur->next;
	cur->next = NULL;
	free(tmp);
	ft_pushfront(stack, n);
}

void	ft_push(t_lst **dst, t_lst **src)
{
	if (!(*src))
		return ;
	ft_pushfront(dst, (*src)->data);
	ft_popfront(src);
}
