/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salfaraw <salfaraw@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:26:29 by salfaraw          #+#    #+#             */
/*   Updated: 2026/02/07 15:26:35 by salfaraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	run_program(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_runtime	rt;
	int			start;

	init_runtime(&rt);
	stack_init(&a);
	stack_init(&b);
	start = handle_flags(argc, argv, &rt, &(int){1});
	if (!read_numbers(&a, &b, argv + start))
		error_exit();
	if (a.size > 1 && !is_sorted(&a))
	{
		rt.disorder = compute_disorder(&a);
		select_sort(&a, &b, &rt);
	}
	if (rt.bench)
		print_bench(&rt);
	stack_free(&a);
	stack_free(&b);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	return (run_program(argc, argv));
}
