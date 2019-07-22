/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:18:29 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/21 18:18:10 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		dups(int ac, char **av)
{
	int	*nums;
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (!(nums = (int *)malloc(sizeof(int) * (ac - 1))))
		exit(1);
	while (--ac)
		nums[i++] = ft_atoi(av[j++]);
	while (i--)
	{
		j = i;
		while (j--)
		{
			if (nums[j] == nums[i])
			{
				free(nums);
				return (1);
			}
		}
	}
	free(nums);
	return (0);
}

static int		not_int(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
		if (!(ft_isdigit(*str++)))
			return (1);
	return (0);
}

static int		big_num(char *str)
{
	long long	long_num;
	int			short_num;

	long_num = ft_atol(str);
	short_num = ft_atoi(str);
	if (long_num != (long)short_num)
		return (1);
	return (0);
}

static int		error_management(char **av, char *join)
{
	write(1, "Error\n", 6);
	free_error(av, join);
	return (1);
}

int				error(int ac, char **av, char *join)
{
	int		ind;
	int		len;

	ind = 1;
	len = ac - 1;
	while (len--)
		if (not_int(av[ind]) || big_num(av[ind++]))
			return (error_management(av, join));
	if (dups(ac, av))
		return (error_management(av, join));
	return (0);
}
