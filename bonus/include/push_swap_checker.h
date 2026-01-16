/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:42:39 by csilva            #+#    #+#             */
/*   Updated: 2026/01/16 08:11:03 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# include "../../push_swap.h"
# include "../../get_next_line/get_next_line.h"

/* checker */

void	exec_operation(char *line, t_stack *a, t_stack *b);
void	exec_op_part2(char *line, t_stack *a, t_stack *b);
void	error_and_exit(t_stack *a, t_stack *b);
void	checker(t_stack *a, t_stack *b);
int		is_stack_sorted(t_stack *a);
int		ft_strcmp(const char *s1, const char *s2);

#endif