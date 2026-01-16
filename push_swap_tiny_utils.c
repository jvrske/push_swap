/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tiny_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:33:33 by csilva            #+#    #+#             */
/*   Updated: 2026/01/15 15:32:55 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(t_stack *a)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	index = 0;
	min = a->array[0];
	while (i < a->size)
	{
		if (a->array[i] < min)
		{
			min = a->array[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	max_index(t_stack *s)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = s->array[0];
	index = 0;
	while (i < s->size)
	{
		if (s->array[i] > max)
		{
			max = s->array[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	min_to_top(t_stack *a)
{
	int	min;

	min = min_index(a);
	if (min == 1)
		ra(a);
	else if (min == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min == 3)
		rra(a);
}

int	is_sorted(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
