/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salfaraw <salfaraw@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:00:39 by salfaraw          #+#    #+#             */
/*   Updated: 2026/02/07 15:02:20 by salfaraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	long	pairs;
	long	mistakes;
	t_node	*i;
	t_node	*j;

	if (!a || a->size < 2)
		return (0.0);
	pairs = 0;
	mistakes = 0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			pairs++;
			if (i->data > j->data)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / (double)pairs);
}
