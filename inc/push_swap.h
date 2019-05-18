/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:36:51 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/18 23:40:19 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

# define MAX(a, b)	b & ((a - b) >> 31) | a & (~(a - b) >> 31)

typedef struct		s_lst
{
	int				data;
	struct s_lst	*next;
}					t_lst;

typedef struct  s_push
{
    t_lst		**lst1;     // keeps the number of elements in blocks
    t_lst		**lst2;
	size_t		s1;			// keeps the size of the stack
	size_t		s2;
    t_lst		**stack1;   // keeps the numbers in stacks
    t_lst		**stack2;
}				t_push;

int     median(t_lst *lst, size_t n);
void    a_partition(t_push *p);
void	b_partition(t_push *p);
void	a_sort(t_push *p);
void	b_sort(t_push *p);
void	a_sort_basic(t_push *p);
void	b_sort_basic(t_push *p);
int		is_sorted(t_lst *lst);

void    ft_swap(t_lst **lst);
void    ft_rotate(t_lst **lst);
void    ft_reverse_rotate(t_lst **lst);
void    ft_push(t_lst **dst, t_lst **src);

t_lst	*ft_newlst(int n);
void	ft_pushfront(t_lst **lst, int n);
void	ft_pushback(t_lst **lst, int n);
void	ft_popfront(t_lst **lst);
t_push	*init(int ac, char **av);
void	ft_printl(t_push *p);
void	ft_printlst(t_lst *lst);

#endif
