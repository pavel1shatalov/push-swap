/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 15:25:14 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/21 16:17:59 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_lst	*ft_newlst(int n)
{
	t_lst	*lst;

	if (!(lst = (t_lst *)malloc(sizeof(t_lst))))
		exit(1);
	lst->data = n;
	lst->next = NULL;
	return (lst);
}

void	ft_pushfront(t_lst **lst, int n)
{
	t_lst	*new;

	new = ft_newlst(n);
	new->next = *lst;
	*lst = new;
}

void	ft_pushback(t_lst **lst, int n)
{
	t_lst	*cur;

	if (!lst)
		return ;
	if (*lst)
	{
		cur = *lst;
		while (cur->next)
			cur = cur->next;
		cur->next = ft_newlst(n);
	}
	else
		*lst = ft_newlst(n);
}

void	ft_popfront(t_lst **lst)
{
	t_lst	*cur;

	if (!(*lst))
		return ;
	cur = (*lst)->next;
	free(*lst);
	*lst = cur;
}
