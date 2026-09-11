/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:01:52 by nelali            #+#    #+#             */
/*   Updated: 2026/02/07 15:05:51 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	if (stack -> size < 2)
		return ;
	node1 = stack -> top;
	node2 = node1 -> next;
	node3 = node2 -> next;
	stack -> top = node2;
	node2 -> prev = NULL;
	node2 -> next = node1;
	node1 -> prev = node2;
	if (stack -> size == 2)
	{
		stack -> bottom = node1;
		node1 -> next = NULL;
	}
	else
	{
		node1 -> next = node3;
		node3 -> prev = node1;
	}
}

void	sa(t_stack *a, t_runtime *rt)
{
	if (a -> size < 2)
		return ;
	swap(a);
	write(1, "sa\n", 3);
	rt -> ops.sa++;
	rt -> ops.total++;
}

void	sb(t_stack *b, t_runtime *rt)
{
	if (b -> size < 2)
		return ;
	swap(b);
	write(1, "sb\n", 3);
	rt -> ops.sb++;
	rt -> ops.total++;
}

void	ss(t_stack *a, t_stack *b, t_runtime *rt)
{
	if (a -> size < 2 && b -> size < 2)
		return ;
	if (a -> size >= 2)
		swap(a);
	if (b -> size >= 2)
		swap(b);
	write(1, "ss\n", 3);
	rt -> ops.ss++;
	rt -> ops.total++;
}
