/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:24:33 by nelali            #+#    #+#             */
/*   Updated: 2026/02/07 15:24:34 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adaptive_sort(t_stack *a, t_stack *b, t_runtime *rt)
{
	if (rt->disorder < 0.2)
		simple_sort(a, b, rt);
	else if (rt->disorder < 0.5)
		medium_sort(a, b, rt);
	else
		complex_sort(a, b, rt);
}

void	select_sort(t_stack *a, t_stack *b, t_runtime *rt)
{
	if (a->size <= 2)
	{
		if (a->size == 2)
			sort_two(a, rt);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a, rt);
		return ;
	}
	if (rt->flags.simple)
		simple_sort(a, b, rt);
	else if (rt->flags.medium)
		medium_sort(a, b, rt);
	else if (rt->flags.complex)
		complex_sort(a, b, rt);
	else
		adaptive_sort(a, b, rt);
}
