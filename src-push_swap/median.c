/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:49:33 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/16 18:49:36 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     *lstoar(t_list *lst, size_t n)
{
	int		*A;
	size_t	ind;

	ind = 0;
	if (!(A = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	while (ind < n)
	{
		A[ind++] = *(int *)lst->content;
        lst = lst->next;
	}
    return A;
}

void    swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

int     partition(int *A, int left, int right)
{
    int pivot;
    int i;
    int x;

    pivot = A[right];
    i = left;
    x = i;
    while (x < right)
    {
        if (A[x] <= pivot)
        {
            swap(&A[i], &A[x]);
            i++;
        }
        x++;
    }
    swap(&A[i], &A[right]);
    return (i);
}

int     quickselect(int *A, int left, int right, int k)
{
    int p;

    p = partition(A, left, right);
    if (k - 1 == p)
        return A[p];
    else if (k - 1 < p)
        return (quickselect(A, left, p - 1, k));
    else
        return (quickselect(A, p + 1, right, k));
}

int     median(t_list *lst, size_t n)
{
    int *A;

    A = lstoar(lst, n);
    return (quickselect(A, 0, n - 1, n / 2)); // I basically don't care and take the smaller one
    free(A);
}
