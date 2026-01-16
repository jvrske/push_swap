/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:29:28 by csilva            #+#    #+#             */
/*   Updated: 2026/01/14 11:02:38 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	check_size(a, b);
	free_all(a, b, array);
	return (0);
}
