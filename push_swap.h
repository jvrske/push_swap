/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:29:31 by csilva            #+#    #+#             */
/*   Updated: 2026/01/15 15:33:42 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_stack
{
	unsigned int	capacity;
	int				size;
	int				*array;
}	t_stack;

/* parser */

void			*ft_calloc(size_t count, size_t size);
unsigned int	ft_countnumbers(char *s);
char			*ft_getnextnum(char *s);
long			ft_atol(char *s);
int				parser(int ac, char *av[], int **array);
int				ft_isdigit(int c);
int				ft_signal(char c);
int				ft_isspace(int c);
int				push_swap(int ac, char *av[]);
int				check_double(int *array, int size);

/* operations */

void			ft_rotate(t_stack *stack);
void			ra(t_stack	*a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);

void			ft_rrotate(t_stack	*stack);
void			rra(t_stack	*a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);

void			ft_swap(t_stack *stack);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);

void			ft_push(t_stack *dst, t_stack *src);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *b, t_stack *a);

/* stack init */

t_stack			*stack_init_a(unsigned int capacity, int	*array);
t_stack			*stack_init_b(unsigned int capacity);
void			free_all(t_stack *a, t_stack *b, int *array);

/* tiny sorts */

void			check_size(t_stack *a, t_stack *b);
void			sort_2(t_stack *a);
void			sort_3(t_stack *a);
void			sort_4(t_stack *a, t_stack *b);
void			sort_5(t_stack *a, t_stack *b);
void			min_to_top(t_stack *a);
int				min_index(t_stack *a);
int				is_sorted(int *array, int size);

/* algorithm */

void			algorithm(t_stack *a, t_stack *b);
void			sort_a(t_stack *a);
void			init_b(t_stack *a, t_stack *b);
void			get_nbr_rot(t_stack *a, t_stack *b, int *rot_a, int *rot_b);
void			rotate_stack(t_stack *s, int rote_s, char flag);
void			rotate_stacks(t_stack *a, t_stack *b, int *rote_a, int *rote_b);
int				max_index(t_stack *s);
int				ft_abs(int n);
int				target_index_a(t_stack *a, int n);

/* indexing */

int				indexing(t_stack *a);
int				count_smaller(t_stack *a, int n);

/* chunks */

void			push_chunk_to_b(t_stack *a, t_stack *b);
void			push_to_b(t_stack *a, t_stack *b, int chunk_min, int chunk_max);
int				exist_in_chunk(t_stack *a, int chunk_max);
int				get_chunk_size(t_stack *a);

#endif