/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_rrotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:07:54 by csilva            #+#    #+#             */
/*   Updated: 2026/01/12 16:02:25 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate(t_stack	*stack)
{
	int	start;
	int	end;
	int	tmp;

	start = 0;
	end = stack->size - 1;
	tmp = stack->array[end];
	while (start < end)
	{
		stack->array[end] = stack->array[end - 1];
		end--;
	}
	stack->array[0] = tmp;
}

void	rra(t_stack	*a)
{
	ft_rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	ft_rrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_rrotate(a);
	ft_rrotate(b);
	write(1, "rrr\n", 4);
}
