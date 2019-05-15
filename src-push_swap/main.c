/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:35:42 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/15 20:37:12 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// To be honest I don't want to include the same functions everywhere

t_list  *init_stack(int ac, char **av)
{
    int     ind;
    int     tmp;
    t_list  *stack;
    t_list  *curr;

    ind = 1;
    tmp = ft_atoi(av[ind++]);
    stack = ft_lstnew(&tmp, sizeof(int));
    ac--;
    curr = stack;
    while (--ac)
    {
        tmp = ft_atoi(av[ind++]);
        curr->next = ft_lstnew(&tmp, sizeof(int));
        curr = curr->next;
    }
    return (stack);
}

int     main(int ac, char **av)
{
    t_list  *stack1;
    t_list  *stack2;

    // Validation is missed

    // Initialization of stack1
    stack1 = init_stack(ac, av);
    ft_printl(stack1, 1);

    // Initialization of stack2
    stack2 = ft_lstnew(NULL, 0);
    ft_printf("_-_\n");
    ft_printl(stack2, 2);

    // I can swap only neighbours
    // thus, let's consider bubble sort first
    bubble_sort(&stack1, ac - 1);
    ft_printl(stack1, 1);
    return (0);
}
