/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:14:37 by csilva            #+#    #+#             */
/*   Updated: 2026/01/09 14:35:16 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *dst, t_stack *src)
{
	int	start;
	int	end;
	int	i;

	if (!src->size)
		return ;
	start = 0;
	i = 0;
	end = dst->size;
	while (start < end)
	{
		end--;
		dst->array[end + 1] = dst->array[end];
	}
	dst->array[0] = src->array[0];
	dst->size++;
	while (i < src->size - 1)
	{
		src->array[i] = src->array[i + 1];
		i++;
	}
	src->size--;
}

void	pa(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	ft_push(b, a);
	write(1, "pb\n", 3);
}
