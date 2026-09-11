/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:22:58 by nelali            #+#    #+#             */
/*   Updated: 2026/02/07 15:23:00 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a, t_runtime *rt)
{
	if (a->top->data > a->top->next->data)
		sa(a, rt);
}

void	sort_three(t_stack *a, t_runtime *rt)
{
	int	x;
	int	y;
	int	z;

	x = a->top->data;
	y = a->top->next->data;
	z = a->bottom->data;
	if (y > x && y < z)
		return ;
	else if (x > y && y < z && x < z)
		sa(a, rt);
	else if (x > y && y > z)
	{
		sa(a, rt);
		rra(a, rt);
	}
	else if (x > y && y < z && x > z)
		ra(a, rt);
	else if (x < y && y > z && x < z)
	{
		sa(a, rt);
		ra(a, rt);
	}
	else if (x < y && y > z && x > z)
		rra(a, rt);
}
