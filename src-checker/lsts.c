/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 15:25:14 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/18 19:37:34 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_lst	*ft_newlst(int n)
{
	t_lst	*lst;

	if (!(lst = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	lst->data = n;
	lst->next = NULL;
	return (lst);
}

void	ft_pushfront(t_lst	**lst, int n)
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

t_push	*init(int ac, char **av)
{
	t_push	*p;
	int 	ind;

	if (!(p = (t_push *)malloc(sizeof(t_push))))
		return (NULL);
	if (!(p->stack1 = (t_lst **)malloc(sizeof(t_lst))))
		return (NULL);
	if (!(*p->stack1 = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	if (!(p->lst1 = (t_lst **)malloc(sizeof(t_lst))))
		return (NULL);
	if (!(*p->lst1 = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	ind = 1;
	ft_pushfront(p->lst1, ac - 1);
	p->s1 = ac - 1;
	*p->stack1 = NULL;
	while (--ac)
		ft_pushback(p->stack1, ft_atoi(av[ind++]));
	if (!(p->stack2 = (t_lst **)malloc(sizeof(t_lst))))
		return (NULL);
	if (!(*p->stack2 = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	if (!(p->lst2 = (t_lst **)malloc(sizeof(t_lst))))
		return (NULL);
	if (!(*p->lst2 = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	*p->lst2 = NULL;
	p->s2 = 0;
	*p->stack2 = NULL;
	return (p);
}

int		ft_prints(t_lst *stack)
{
	if (stack)
	{
		ft_printf("%5d     ", stack->data);
		return (1);
	}
	else
	{
		ft_printf("          ");
		return (0);
	}
}

void	ft_printl(t_push *p)
{
	size_t	size;
	t_lst	*stack1;
	t_lst	*stack2;

	stack1 = *p->stack1;
	stack2 = *p->stack2;
	size = MAX(p->s1, p->s2);
	while (size--)
	{
		ft_printf("| ");
		if (ft_prints(stack1))
			stack1 = stack1->next;
		ft_printf("|\t| ");
		if (ft_prints(stack2))
			stack2 = stack2->next;
		ft_printf("|\n");
	}
	ft_printf(" -----------     -----------\n");
}
