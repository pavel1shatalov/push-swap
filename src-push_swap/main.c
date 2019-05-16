/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:35:42 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/16 20:38:55 by ggerhold         ###   ########.fr       */
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
	// later I should only initialize the final structure
    t_list  *stack1;
    t_list  *stack2;
	t_push	*p;
	int		size;
	t_list	*list1;
	t_list	*list2;

	// size of the stack
	size = ac - 1;

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
    //  bubble_sort(&stack1, ac - 1);
    //  ft_printl(stack1, 1);

    // searching for a median
    //  ft_printf("median of stack A is %d\n", median(stack1, ac - 1));

	// let's for a moment consider this structure
	p = (t_push *)malloc(sizeof(t_push));
	if (!p)
		return (0);
	p->stack1 = &stack1;
	p->stack2 = &stack2;
	list1 = ft_lstnew(&size, sizeof(int));
	p->lst1 = &list1;
	list2 = ft_lstnew(NULL, 0);
	p->lst2 = &list2;

	// check out how it partitioned the first stack
	a_partition(p);
	return (0);
}
