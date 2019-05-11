/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:33:49 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/12 02:32:02 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void    read_instructions(t_list **stack1, t_list **stack2)
{
    char *command;
    // to ignore unused parameter
    if (!stack2)
        return ;

    while (get_next_line(0, &command))
    {
        // stop command is just for debugging
        if (!ft_strcmp("q", command)) 
            return ;

        if (!ft_strcmp("sa", command))
            ft_swap(stack1); // Done
        else if (!ft_strcmp("sb", command))
            ft_swap(stack2); // Done
        else if (!ft_strcmp("ss", command))
        {
            ft_swap(stack1); // Done
            ft_swap(stack2); // Done
        }
        else if (!ft_strcmp("pa", command))
            ft_push(stack1, stack2); // Done
        else if (!ft_strcmp("pb", command))
            ft_push(stack2, stack1); // Done
        else if (!ft_strcmp("ra", command))
            ft_rotate(stack1); // Done
        else if (!ft_strcmp("rb", command))
            ft_rotate(stack2); // Done
        else if (!ft_strcmp("rr", command))
        {
            ft_rotate(stack1); // Done
            ft_rotate(stack2); // Done
        }
        else if (!ft_strcmp("rra", command))
            ft_reverse_rotate(stack1); // Done
        else if (!ft_strcmp("rrb", command))
            ft_reverse_rotate(stack2); // Done
        else if (!ft_strcmp("rrr", command))
        {
            ft_reverse_rotate(stack2); // Done
            ft_reverse_rotate(stack2); // Done
        }
        else
            ft_printf("incorrect command\n"); // has to be Error
    }
}

void    ft_check(t_list *lst)
{
    while (lst && lst->next)
    {
        if (*(int *)lst->content > *(int *)lst->next->content)
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
    t_list  *stack1;
    t_list  *stack2;
    
    // Validation is missed

    // Initialization of stack below
    stack1 = init_stack(ac, av);
    ft_printl(stack1, 1);
    // There are a few problems with the second stack
    // It can't be absolutely empty
    // Although, I can change my functions for the cases when stack1 or stack2 are empty
    // It's only for push methods
    stack2 = ft_lstnew(NULL, 0);
    ft_printf("_-_\n");
    ft_printl(stack2, 2);
    
    // Reading the instructions
    read_instructions(&stack1, &stack2);
    ft_printl(stack1, 1);
    ft_printf("_-_\n");
    ft_printl(stack2, 2);

    // Check if it's sorted
    ft_check(stack1);
    return (0);
}