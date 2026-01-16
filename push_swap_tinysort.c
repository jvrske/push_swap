/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tinysort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:38:01 by csilva            #+#    #+#             */
/*   Updated: 2026/01/09 13:55:11 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_size(t_stack *a, t_stack *b)
{
	if (a->size == 1)
		return ;
	if (a->size == 2)
		sort_2(a);
	if (a->size == 3)
		sort_3(a);
	if (a->size == 4)
		sort_4(a, b);
	if (a->size == 5)
		sort_5(a, b);
	else
		algorithm(a, b);
}

void	sort_2(t_stack *a)
{
	if (a->array[0] > a->array[1])
		sa(a);
}

void	sort_3(t_stack *a)
{
	int	i;
	int	j;
	int	k;

	i = a->array[0];
	j = a->array[1];
	k = a->array[2];
	if (i > j && j < k && i < k)
		sa(a);
	else if (i > j && j > k)
	{
		sa(a);
		rra(a);
	}
	else if (i > j && j < k && i > k)
		ra(a);
	else if (i < j && j > k && i < k)
	{
		sa(a);
		ra(a);
	}
	else if (i < j && j > k && i > k)
		rra(a);
}

void	sort_4(t_stack *a, t_stack *b)
{
	min_to_top(a);
	pb(b, a);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	min_to_top(a);
	pb(b, a);
	min_to_top(a);
	pb(b, a);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
