/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkerutils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:35:20 by csilva            #+#    #+#             */
/*   Updated: 2026/01/16 08:10:38 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_checker.h"

void	checker(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		exec_operation(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (is_stack_sorted(a))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

void	exec_operation(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "sa\n"))
		ft_swap(a);
	else if (!ft_strcmp(line, "sb\n"))
		ft_swap(b);
	else if (!ft_strcmp(line, "ss\n"))
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (!ft_strcmp(line, "pa\n"))
		ft_push(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		ft_push(b, a);
	else
		exec_op_part2(line, a, b);
}

void	exec_op_part2(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "ra\n"))
		ft_rotate(a);
	else if (!ft_strcmp(line, "rb\n"))
		ft_rotate(b);
	else if (!ft_strcmp(line, "rr\n"))
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else if (!ft_strcmp(line, "rra\n"))
		ft_rrotate(a);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_rrotate(b);
	else if (!ft_strcmp(line, "rrr\n"))
	{
		ft_rrotate(a);
		ft_rrotate(b);
	}
	else
		error_and_exit(a, b);
}

int	is_stack_sorted(t_stack *a)
{
	int	i;

	i = 0;
	if (!a || a->size <= 1)
		return (1);
	while (i < a->size - 1)
	{
		if (a->array[i] > a->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}


