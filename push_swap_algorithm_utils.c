/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:56:00 by csilva            #+#    #+#             */
/*   Updated: 2026/01/14 13:28:58 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_nbr_rot(t_stack *a, t_stack *b, int *rot_a, int *rot_b)
{
	int	total_cost;
	int	cost_a;
	int	cost_b;
	int	i;

	i = 0;
	total_cost = INT_MAX;
	while (i < b->size)
	{
		cost_a = target_index_a(a, b->array[i]);
		if (cost_a >= a->size / 2)
			cost_a = a->size - cost_a;
		if (i <= b->size / 2)
			cost_b = i;
		else
			cost_b = b->size - i;
		if (total_cost > cost_a + cost_b || (total_cost == cost_a + cost_b))
		{
			total_cost = cost_a + cost_b;
			*rot_a = target_index_a(a, b->array[i]);
			*rot_b = i;
		}
		i++;
	}
}

void	rotate_stacks(t_stack *a, t_stack *b, int *rote_a, int *rote_b)
{
	if (*rote_a < a->size / 2 && *rote_b < b->size / 2)
	{
		while (*rote_a > 0 && *rote_b > 0)
		{
			rr(a, b);
			(*rote_a)--;
			(*rote_b)--;
		}
	}
	else if (*rote_a >= a->size / 2 && *rote_b >= b->size / 2)
	{
		while (*rote_a < a->size && *rote_b < b->size)
		{
			rrr(a, b);
			(*rote_a)++;
			(*rote_b)++;
		}
	}
}

void	rotate_stack(t_stack *s, int cost, char flag)
{
	if (cost < s->size / 2)
	{
		while (cost > 0)
		{
			if (flag == 'a')
				ra(s);
			else
				rb(s);
			cost--;
		}
	}
	else
	{
		while (cost < s->size)
		{
			if (flag == 'a')
				rra(s);
			else
				rrb(s);
			cost++;
		}
	}
}

void	sort_a(t_stack *a)
{
	int	min;
	int	i;

	i = 0;
	min = min_index(a);
	if (min <= a->size / 2)
	{
		while (min > 0)
		{
			ra(a);
			min--;
		}
	}
	else
	{
		while (min < a->size)
		{
			rra(a);
			min++;
		}
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
