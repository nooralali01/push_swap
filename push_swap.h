/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:28:19 by nelali            #+#    #+#             */
/*   Updated: 2026/02/07 15:33:47 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
}	t_flags;

typedef struct s_chunk
{
	int	count;
	int	size;
	int	index;
	int	min;
	int	max;
}	t_chunk;

typedef struct s_opcount
{
	long	sa;
	long	sb;
	long	ss;
	long	pa;
	long	pb;
	long	ra;
	long	rb;
	long	rr;
	long	rra;
	long	rrb;
	long	rrr;
	long	total;
}	t_opcount;

typedef struct s_runtime
{
	t_flags		flags;
	t_opcount	ops;
	double		disorder;
	int			bench;
}	t_runtime;

char	**split_words(char **argv);
void	stack_init(t_stack *stack);
void	stack_free(t_stack *stack);
void	free_words(char **words);

void	sa(t_stack *a, t_runtime *rt);
void	sb(t_stack *b, t_runtime *rt);
void	ss(t_stack *a, t_stack *b, t_runtime *rt);
void	pa(t_stack *a, t_stack *b, t_runtime *rt);
void	pb(t_stack *a, t_stack *b, t_runtime *rt);
void	ra(t_stack *a, t_runtime *rt);
void	rb(t_stack *b, t_runtime *rt);
void	rr(t_stack *a, t_stack *b, t_runtime *rt);
void	rra(t_stack *a, t_runtime *rt);
void	rrb(t_stack *b, t_runtime *rt);
void	rrr(t_stack *a, t_stack *b, t_runtime *rt);

int		is_number(char *str);
int		string_to_int(char *str, int *num);
int		has_duplicates(int *arr, int count);
int		fill_stack(t_stack *a, int *arr, int count);
int		read_numbers(t_stack *a, t_stack *b, char **argv);
int		is_sorted(t_stack *stack);
int		handle_flags(int argc, char **argv, t_runtime *rt, int *i);

double	compute_disorder(t_stack *a);

void	simple_sort(t_stack *a, t_stack *b, t_runtime *rt);
void	simple_sorted(t_stack *a, t_stack *b, t_runtime *rt);
void	medium_sort(t_stack *a, t_stack *b, t_runtime *rt);
void	complex_sort(t_stack *a, t_stack *b, t_runtime *rt);

void	sort_two(t_stack *a, t_runtime *rt);
void	sort_three(t_stack *a, t_runtime *rt);

void	select_sort(t_stack *a, t_stack *b, t_runtime *rt);
void	init_runtime(t_runtime *rt);
void	print_bench(t_runtime *rt);
void	print_bench_ops(t_runtime *rt);

int		int_sqrt(int n);
void	normalize_stack(t_stack *a);
void	error_exit(void);

#endif
