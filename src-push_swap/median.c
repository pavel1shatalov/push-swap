/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:49:33 by ggerhold          #+#    #+#             */
/*   Updated: 2019/07/21 19:19:33 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		*lstoar(t_lst *lst, size_t n)
{
	int		*a;
	size_t	ind;

	ind = 0;
	if (!(a = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	while (ind < n)
	{
		a[ind++] = lst->data;
		lst = lst->next;
	}
	return (a);
}

static void		swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

static int		partition(int *a, int left, int right)
{
	int pivot;
	int i;
	int x;

	pivot = a[right];
	i = left;
	x = i;
	while (x < right)
	{
		if (a[x] <= pivot)
		{
			swap(&a[i], &a[x]);
			i++;
		}
		x++;
	}
	swap(&a[i], &a[right]);
	return (i);
}

static int		quickselect(int *a, int left, int right, int k)
{
	int p;

	p = partition(a, left, right);
	if (k - 1 == p)
		return (a[p]);
	else if (k - 1 < p)
		return (quickselect(a, left, p - 1, k));
	else
		return (quickselect(a, p + 1, right, k));
}

int				median(t_lst *lst, size_t n)
{
	int *a;
	int med;

	if (!(a = lstoar(lst, n)))
		exit(1);
	med = quickselect(a, 0, n - 1, n / 2 + n % 2);
	free(a);
	return (med);
}
