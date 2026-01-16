/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:12:19 by csilva            #+#    #+#             */
/*   Updated: 2026/01/15 15:36:34 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_stack *a, t_stack *b)
{
	int	rot_a;
	int	rot_b;

	if (!indexing(a))
	{
		write (2, "Error\n", 6);
		free_all(a, b, NULL);
		exit(1);
	}
	push_chunk_to_b(a, b);
	sort_3(a);
	while (b->size > 0)
	{
		get_nbr_rot(a, b, &rot_a, &rot_b);
		rotate_stacks(a, b, &rot_a, &rot_b);
		rotate_stack(a, rot_a, 'a');
		rotate_stack(b, rot_b, 'b');
		pa(a, b);
	}
	sort_a(a);
}

int	target_index_a(t_stack *a, int n)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (n > a->array[i] && n < a->array[i + 1])
			return (i + 1);
		i++;
	}
	if (a->array[a->size - 1] < n && a->array[0] > n)
		return (0);
	return (max_index(a) + 1);
}
