/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:36:51 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/22 12:56:14 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct		s_lst
{
	int				data;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_swap
{
	char			*command;
	struct s_swap	*next;
}					t_swap;

typedef struct		s_push
{
	t_lst			*lst1;
	t_lst			*lst2;
	int				s1;
	int				s2;
	t_lst			*stack1;
	t_lst			*stack2;
	t_swap			*sequence;
}					t_push;

void				a_partition(t_push *p);
void				b_partition(t_push *p);
void				a_sort(t_push *p);
void				b_sort(t_push *p);

void				a3sort_slm(t_push *p);
void				a3sort_mls(t_push *p);
void				a3sort_msl(t_push *p);
void				a3sort_lsm(t_push *p);
void				a3sort_lms(t_push *p);

void				a3sort_slm_vip(t_push *p);
void				a3sort_mls_vip(t_push *p);
void				a3sort_msl_vip(t_push *p);
void				a3sort_lsm_vip(t_push *p);
void				a3sort_lms_vip(t_push *p);

void				b3sort_sml(t_push *p);
void				b3sort_slm(t_push *p);
void				b3sort_mls(t_push *p);
void				b3sort_msl(t_push *p);
void				b3sort_lsm(t_push *p);

void				b3sort_sml_vip(t_push *p);
void				b3sort_slm_vip(t_push *p);
void				b3sort_mls_vip(t_push *p);
void				b3sort_msl_vip(t_push *p);
void				b3sort_lsm_vip(t_push *p);

void				ft_swap(t_lst **lst);
void				ft_rotate(t_lst **lst);
void				ft_reverse_rotate(t_lst **lst);
void				ft_push(t_lst **dst, t_lst **src);

void				ft_ra_count(t_push *p, int *count);
void				ft_rb_count(t_push *p, int *count);
void				ft_ra(t_push *p);
void				ft_rb(t_push *p);
void				ft_rra(t_push *p);
void				ft_rrb(t_push *p);
void				ft_sa(t_push *p);
void				ft_sb(t_push *p);
void				ft_pa(t_push *p);
void				ft_pb(t_push *p);

t_lst				*ft_newlst(int n);
void				ft_pushfront(t_lst **lst, int n);
void				ft_pushback(t_lst **lst, int n);
void				ft_popfront(t_lst **lst);
void				ft_pushback_command(t_push *p, char *str);
void				ft_print_sequence(t_swap *s);

t_push				*init(int ac, char **av);
int					error(int ac, char **av, char *join);
int					median(t_lst *lst, size_t n);
void				merge(t_push *p);
void				free_error(char **split, char *join);
void				free_all(t_push *p, char **split, char *join);
int					is_sorted(t_lst *lst, int len);
int					is_top_sorted(t_push *p);

#endif
