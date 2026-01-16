/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:07:40 by csilva            #+#    #+#             */
/*   Updated: 2026/01/15 15:37:00 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(t_stack *a)
{
	if (a->size <= 100)
		return (1);
	return (8);
}

void	push_chunk_to_b(t_stack *a, t_stack *b)
{
	int	chunk_len;
	int	chunk_count;
	int	chunk_max;
	int	current_chunk;

	chunk_count = get_chunk_size(a);
	chunk_len = a->size / chunk_count;
	current_chunk = 0;
	chunk_max = chunk_len;
	while (a->size > 3)
	{
		push_to_b(a, b, current_chunk * chunk_len, chunk_max);
		chunk_max += chunk_len;
		current_chunk++;
		if (current_chunk == chunk_count - 1)
			chunk_max = INT_MAX;
	}
}

int	exist_in_chunk(t_stack *a, int chunk_max)
{
	int	i;

	i = 0;
	while (i < chunk_max)
	{
		if (a->array[i] <= chunk_max)
			return (i);
		i++;
	}
	return (-1);
}

void	push_to_b(t_stack *a, t_stack *b, int chunk_min, int chunk_max)
{
	int	rotations;

	rotations = 0;
	while (a->size > 3)
	{
		rotations = exist_in_chunk(a, chunk_max);
		if (rotations == -1)
			return ;
		rotate_stack(a, rotations, 'a');
		pb(b, a);
		if (b->array[0] > chunk_min && b->array[0]
			< (chunk_min + chunk_max) / 2)
			rb(b);
	}
}
