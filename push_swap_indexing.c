/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_indexing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:42:12 by csilva            #+#    #+#             */
/*   Updated: 2026/01/14 11:24:28 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_smaller(t_stack *a, int n)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < a->size)
	{
		if (a->array[i] < n)
			c++;
		i++;
	}
	return (c);
}

int	indexing(t_stack *a)
{
	int	*tmp;
	int	i;

	tmp = malloc(sizeof(int) * a->size);
	if (!tmp)
		return (0);
	i = 0;
	while (i < a->size)
	{
		tmp[i] = count_smaller(a, a->array[i]);
		i++;
	}
	i = 0;
	while (i < a->size)
	{
		a->array[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (1);
}
