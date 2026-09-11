/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:07:45 by nelali            #+#    #+#             */
/*   Updated: 2026/02/07 15:09:40 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (stack -> size < 2)
		return ;
	first = stack -> top;
	second = first -> next;
	last = stack -> bottom;
	stack -> top = second;
	second -> prev = NULL;
	last -> next = first;
	first -> prev = last;
	first -> next = NULL;
	stack -> bottom = first;
}

void	ra(t_stack *a, t_runtime *rt)
{
	if (a -> size < 2)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
	rt -> ops.ra++;
	rt -> ops.total++;
}

void	rb(t_stack *b, t_runtime *rt)
{
	if (b -> size < 2)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
	rt -> ops.rb++;
	rt -> ops.total++;
}

void	rr(t_stack *a, t_stack *b, t_runtime *rt)
{
	if (a -> size < 2 && b->size < 2)
		return ;
	if (a -> size >= 2)
		rotate(a);
	if (b -> size >= 2)
		rotate(b);
	write(1, "rr\n", 3);
	rt -> ops.rr++;
	rt -> ops.total++;
}
