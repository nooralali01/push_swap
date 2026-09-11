/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salfaraw <salfaraw@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:49:22 by salfaraw          #+#    #+#             */
/*   Updated: 2026/02/07 14:50:32 by salfaraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	print_ops_swap(t_runtime *rt)
{
	ft_putstr_fd("sa: ", 2);
	ft_putnbr_fd(rt->ops.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(rt->ops.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(rt->ops.ss, 2);
}

static void	print_ops_push(t_runtime *rt)
{
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(rt->ops.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(rt->ops.pb, 2);
}

static void	print_ops_rotate(t_runtime *rt)
{
	ft_putstr_fd("ra: ", 2);
	ft_putnbr_fd(rt->ops.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(rt->ops.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(rt->ops.rr, 2);
}

static void	print_ops_reverse_rotate(t_runtime *rt)
{
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(rt->ops.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(rt->ops.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(rt->ops.rrr, 2);
}

void	print_bench_ops(t_runtime *rt)
{
	print_ops_swap(rt);
	print_ops_push(rt);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ", 2);
	print_ops_rotate(rt);
	print_ops_reverse_rotate(rt);
	ft_putchar_fd('\n', 2);
}
