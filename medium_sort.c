/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:22:01 by nelali            #+#    #+#             */
/*   Updated: 2026/02/07 15:22:04 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_value(t_stack *b)
{
	t_node	*cur;
	int		max;

	cur = b->top;
	max = cur->data;
	while (cur)
	{
		if (cur->data > max)
			max = cur->data;
		cur = cur->next;
	}
	return (max);
}

static void	rotate_b_to_top(t_stack *b, int max, t_runtime *rt)
{
	t_node	*cur;
	int		pos;
	int		i;

	cur = b->top;
	pos = 0;
	while (cur && cur->data != max)
	{
		pos++;
		cur = cur->next;
	}
	if (pos <= b->size / 2)
	{
		i = 0;
		while (i++ < pos)
			rb(b, rt);
	}
	else
	{
		i = 0;
		while (i++ < b->size - pos)
			rrb(b, rt);
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b, t_runtime *rt)
{
	int	max;

	while (b->size > 0)
	{
		max = find_max_value(b);
		rotate_b_to_top(b, max, rt);
		pa(a, b, rt);
	}
}

static void	push_chunk_to_b(
	t_stack *a,
	t_stack *b,
	t_chunk *ch,
	t_runtime *rt
)
{
	int	pushed;

	pushed = 0;
	while (pushed < (ch->max - ch->min))
	{
		if (a->top->data >= ch->min && a->top->data < ch->max)
		{
			pb(a, b, rt);
			pushed++;
		}
		else
			ra(a, rt);
	}
}

void	medium_sort(t_stack *a, t_stack *b, t_runtime *rt)
{
	t_chunk	ch;
	int		n;

	normalize_stack(a);
	n = a->size;
	ch.count = int_sqrt(n);
	if (ch.count < 1)
		ch.count = 1;
	ch.size = n / ch.count;
	ch.index = 0;
	while (ch.index < ch.count)
	{
		ch.min = ch.index * ch.size;
		if (ch.index == ch.count - 1)
			ch.max = n;
		else
			ch.max = ch.min + ch.size;
		push_chunk_to_b(a, b, &ch, rt);
		ch.index++;
	}
	push_back_to_a(a, b, rt);
}
