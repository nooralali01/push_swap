/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:10:53 by nelali            #+#    #+#             */
/*   Updated: 2026/02/07 15:15:07 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*prev_last;
	t_node	*last;

	if (stack -> size < 2)
		return ;
	first = stack -> top;
	last = stack -> bottom;
	prev_last = last -> prev;
	prev_last -> next = NULL;
	stack -> bottom = prev_last;
	last -> prev = NULL;
	last -> next = first;
	stack -> top = last;
	first -> prev = last;
}

void	rra(t_stack *a, t_runtime *rt)
{
	if (a -> size < 2)
		return ;
	reverse_rotate(a);
	write(1, "rra\n", 4);
	rt -> ops.rra++;
	rt -> ops.total++;
}

void	rrb(t_stack *b, t_runtime *rt)
{
	if (b -> size < 2)
		return ;
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	rt -> ops.rrb++;
	rt -> ops.total++;
}

void	rrr(t_stack *a, t_stack *b, t_runtime *rt)
{
	if (a -> size < 2 && b -> size < 2)
		return ;
	if (a -> size >= 2)
		reverse_rotate(a);
	if (b -> size >= 2)
		reverse_rotate(b);
	write(1, "rrr\n", 4);
	rt -> ops.rrr++;
	rt -> ops.total++;
}
