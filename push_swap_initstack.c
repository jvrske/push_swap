/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_initstack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:31:12 by csilva            #+#    #+#             */
/*   Updated: 2026/01/14 10:59:00 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init_a(unsigned int capacity, int	*array)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (free_all(stack, NULL, array), NULL);
	stack->capacity = capacity;
	stack->array = array;
	stack->size = capacity;
	return (stack);
}

t_stack	*stack_init_b(unsigned int capacity)
{
	t_stack	*stack;
	int		*array;

	array = malloc(sizeof(int) * capacity);
	if (!array)
		return (free_all(NULL, NULL, array), NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (free_all(NULL, stack, array), NULL);
	stack->capacity = capacity;
	stack->array = array;
	stack->size = 0;
	return (stack);
}

void	free_all(t_stack *a, t_stack *b, int *array)
{
	if (a && a->array)
		free(a->array);
	if (b && b->array)
		free(b->array);
	if (a)
		free(a);
	if (b)
		free(b);
	else if (array)
		free(array);
}
