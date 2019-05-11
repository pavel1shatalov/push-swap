/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:37:26 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/12 01:56:33 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

void    ft_printl(t_list *lst, char num);
void    ft_swap(t_list **lst);
void    ft_rotate(t_list **lst);
void    ft_reverse_rotate(t_list **lst);
void    ft_push(t_list **dst, t_list **src);

#endif