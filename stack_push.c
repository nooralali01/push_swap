/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:17:28 by nelali            #+#    #+#             */
/*   Updated: 2026/02/07 15:17:30 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*pop_top(t_stack *stack)
{
	t_node	*temp;

	if (stack->size == 0)
		return (NULL);
	temp = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = temp->next;
		stack->top->prev = NULL;
	}
	stack->size--;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

static void	push_top(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
	{
		node->next = NULL;
		node->prev = NULL;
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->next = stack->top;
		node->prev = NULL;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

void	pa(t_stack *a, t_stack *b, t_runtime *rt)
{
	t_node	*node;

	if (b->size == 0)
		return ;
	node = pop_top(b);
	if (!node)
		return ;
	push_top(a, node);
	write(1, "pa\n", 3);
	rt->ops.pa++;
	rt->ops.total++;
}

void	pb(t_stack *a, t_stack *b, t_runtime *rt)
{
	t_node	*node;

	if (a->size == 0)
		return ;
	node = pop_top(a);
	if (!node)
		return ;
	push_top(b, node);
	write(1, "pb\n", 3);
	rt->ops.pb++;
	rt->ops.total++;
}
