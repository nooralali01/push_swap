/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salfaraw <salfaraw@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:43:17 by salfaraw          #+#    #+#             */
/*   Updated: 2026/02/07 14:48:10 by salfaraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	print_bench_disorder(t_runtime *rt)
{
	int	integer;
	int	decimal;

	integer = (int)(rt->disorder * 100);
	decimal = (int)(rt->disorder * 10000) % 100;
	ft_putstr_fd("disorder: ", 2);
	ft_putnbr_fd(integer, 2);
	ft_putchar_fd('.', 2);
	if (decimal < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_bench_strategy(t_runtime *rt)
{
	ft_putstr_fd("strategy: ", 2);
	if (rt ->flags.simple)
		ft_putstr_fd("Simple / O(n^2)", 2);
	else if (rt->flags.medium)
		ft_putstr_fd("Medium / O(n√n)", 2);
	else if (rt->flags.complex)
		ft_putstr_fd("Complex / O(n log n)", 2);
	else
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (rt -> disorder < 0.2)
			ft_putstr_fd("O(n)", 2);
		else if (rt -> disorder < 0.5)
			ft_putstr_fd("O(n√n)", 2);
		else
			ft_putstr_fd("O(n log n)", 2);
	}
	ft_putchar_fd('\n', 2);
}

static void	print_bench_total_ops(t_runtime *rt)
{
	ft_putstr_fd("total_ops: ", 2);
	ft_putnbr_fd(rt->ops.total, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_runtime *rt)
{
	ft_putstr_fd("[bench] ", 2);
	print_bench_disorder(rt);
	ft_putstr_fd("[bench] ", 2);
	print_bench_strategy(rt);
	ft_putstr_fd("[bench] ", 2);
	print_bench_total_ops(rt);
	ft_putstr_fd("[bench] ", 2);
	print_bench_ops(rt);
}
