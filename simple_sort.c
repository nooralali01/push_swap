/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:23:22 by nelali            #+#    #+#             */
/*   Updated: 2026/02/07 15:23:23 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *a)
{
	t_node	*current;
	int		min;

	current = a->top;
	min = current->data;
	while (current)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}

static int	find_index(t_stack *a, int value)
{
	t_node	*current;
	int		index;

	current = a->top;
	index = 0;
	while (current)
	{
		if (current->data == value)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

void	simple_sorted(t_stack *a, t_stack *b, t_runtime *rt)
{
	int	min;
	int	idx;

	while (a->size > 1)
	{
		min = find_min(a);
		idx = find_index(a, min);
		if (idx <= a->size / 2)
		{
			while (idx-- > 0)
				ra(a, rt);
		}
		else
		{
			idx = a->size - idx;
			while (idx-- > 0)
				rra(a, rt);
		}
		pb(a, b, rt);
	}
	while (b->size > 0)
		pa(a, b, rt);
}

void	simple_sort(t_stack *a, t_stack *b, t_runtime *rt)
{
	if (a->size == 2)
		sort_two(a, rt);
	else if (a->size == 3)
		sort_three(a, rt);
	else if (a->size >= 4 && a->size <= 20)
		simple_sorted(a, b, rt);
	else
		medium_sort(a, b, rt);
}
