/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:33:49 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/18 19:37:33 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    read_instructions(t_push *p)
{
    char *command;

    while (get_next_line(0, &command))
    {
        // quit command is just for debugging
        if (!ft_strcmp("q", command))
            return ;

        if (!ft_strcmp("sa", command))
            ft_swap(p->stack1); // Done
        else if (!ft_strcmp("sb", command))
            ft_swap(p->stack2); // Done
        else if (!ft_strcmp("ss", command))
        {
            ft_swap(p->stack1); // Done
            ft_swap(p->stack2); // Done
        }
        else if (!ft_strcmp("pa", command))
            ft_push(p->stack1, p->stack2); // Done
        else if (!ft_strcmp("pb", command))
            ft_push(p->stack2, p->stack1); // Done
        else if (!ft_strcmp("ra", command))
            ft_rotate(p->stack1); // Done
        else if (!ft_strcmp("rb", command))
            ft_rotate(p->stack2); // Done
        else if (!ft_strcmp("rr", command))
        {
            ft_rotate(p->stack1); // Done
            ft_rotate(p->stack2); // Done
        }
        else if (!ft_strcmp("rra", command))
            ft_reverse_rotate(p->stack1); // Done
        else if (!ft_strcmp("rrb", command))
            ft_reverse_rotate(p->stack2); // Done
        else if (!ft_strcmp("rrr", command))
        {
            ft_reverse_rotate(p->stack2); // Done
            ft_reverse_rotate(p->stack2); // Done
        }
        else
            ft_printf("incorrect command\n"); //- has to be Error
    }
}

void    ft_check(t_lst *lst)
{
    while (lst && lst->next)
    {
        if (lst->data > lst->next->data)
        {
            ft_printf("KO\n");
            return ;
        }
        lst = lst->next;
    }
    ft_printf("OK\n");
}

int     main(int ac, char **av)
{
	t_push	*p;

	p = init(ac, av);
	ft_printl(p);

    // Reading the instructions
    read_instructions(p);
	ft_printl(p);

    // Check if it's sorted
    ft_check(*p->stack1);
    return (0);
}
