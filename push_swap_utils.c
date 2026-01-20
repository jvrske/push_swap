/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:51:15 by csilva            #+#    #+#             */
/*   Updated: 2026/01/20 13:08:49 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_signal(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\0' || c == '\n' || c == '\t');
}

unsigned int	ft_countnumbers(char *s)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && ft_isspace(s[i + 1]))
			nbr++;
		i++;
	}
	return (nbr);
}

char	*ft_getnextnum(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	return (s + i);
}
