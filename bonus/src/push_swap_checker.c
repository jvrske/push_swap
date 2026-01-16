/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:42:12 by csilva            #+#    #+#             */
/*   Updated: 2026/01/16 08:04:10 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_checker.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		*array;
	int		len;
	int		i;

	i = 1;
	len = 0;
	if (ac <= 1)
		return ((write(2, "Error\n", 6), 0));
	while (av[i++])
		len += ft_countnumbers(av[i - 1]);
	if (parser(ac, av, &array))
		return (write(2, "Error\n", 6), 0);
	if (is_sorted(array, len))
		return (free_all(NULL, NULL, array), 0);
	a = stack_init_a(len, array);
	b = stack_init_b(len);
	if (!a || !b)
		return (free_all(a, b, array), write(2, "Error\n", 6), 0);
	checker(a, b);
	free_all(a, b, array);
	return (0);
}

void	error_and_exit(t_stack *a, t_stack *b)
{
	free_all(a, b, NULL);
	write(2, "Error\n", 6);
	exit(1);
}
