/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 19:28:03 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/16 20:47:07 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// I made function memndel for lstdelone purposes
// it's located in libft

// What if I can't do a given instruction?

void    ft_printl(t_list *lst, char num)
{
	if (!lst->content)
    {
		ft_printf("%d stack is empty\n", num);
        return ;
    }
    while (lst)
    {
        ft_printf("% d\n", *(int *)lst->content);
        lst = lst->next;
    }
    num == 1 ? ft_printf(" _\n a\n") : ft_printf(" _\n b\n");
}

void    ft_swap(t_list **lst)
{
    void    *tmp;

    if (*lst && (*lst)->next)
    {
        tmp = (*lst)->content;
        (*lst)->content = (*lst)->next->content;
        (*lst)->next->content = tmp;
    }
}

void    ft_reverse_rotate(t_list **lst)
{
    void    *tmp;
    t_list	*head;
	t_list	*tail;

    if (!(*lst) || !(*lst)->next)
		return ;
    tail = (*lst);
	while (tail->next->next)
		tail = tail->next;
	tmp = tail->next->content;
	head = ft_lstnew(tmp, sizeof(tmp)); // don't understand why sizeof(tmp) [void *tmp]
	head->next = (*lst);
	(*lst) = head;
	ft_lstdelone(&(tail->next), ft_memndel);
	tail->next = NULL; // it becomes a problem unless you do it explicitly
}

void    ft_rotate(t_list **lst)
{
    void    *tmp;
    t_list  *cur;

    if (!(*lst) || !(*lst)->next)
        return ;
    tmp = (*lst)->content;
    cur = (*lst)->next;
    while (cur->next)
        cur = cur->next;
    cur->next = ft_lstnew(tmp, sizeof(tmp));
    cur = (*lst)->next;
    ft_lstdelone(lst, ft_memndel);
    (*lst) = cur;
}

void	ft_push(t_list **dst, t_list **src)
{
    void    *tmp;
    t_list	*head;

	if (!(*dst) || !(*src) || !((*src)->content))
		return ;
    // it has to work even with !(*lst->content)
	tmp = (*src)->content;
	if ((*dst)->content)
	{
		head = ft_lstnew(tmp, sizeof(tmp));
		head->next = (*dst);
		(*dst) = head;
	}
	else
	{
		(*dst)->content = ft_memalloc(sizeof(tmp));
		if (!(*dst)->content)
			return ;
		(*dst)->content = ft_memcpy((*dst)->content, tmp, sizeof(tmp));
	}
	head = (*src)->next;
	ft_lstdelone(src, ft_memndel);
	(*src) = head ? head : ft_lstnew(NULL, 0);
}
