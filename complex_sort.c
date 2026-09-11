/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salfaraw <salfaraw@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:51:30 by salfaraw          #+#    #+#             */
/*   Updated: 2026/02/07 14:59:46 by salfaraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_max_bits(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static int	*stack_to_array(t_stack *a)
{
	int		*arr;
	t_node	*cur;
	int		i;

	arr = malloc(sizeof(int) * a -> size);
	if (!arr)
		return (NULL);
	cur = a -> top;
	i = 0;
	while (cur)
	{
		arr[i] = cur -> data;
		i++;
		cur = cur -> next;
	}
	return (arr);
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	normalize_stack(t_stack *a)
{
	int		*arr;
	t_node	*cur;
	int		i;

	arr = stack_to_array(a);
	if (!arr)
		error_exit();
	sort_array(arr, a -> size);
	cur = a -> top;
	while (cur)
	{
		i = 0;
		while (i < a -> size)
		{
			if (cur -> data == arr[i])
			{
				cur -> data = i;
				break ;
			}
			i++;
		}
		cur = cur -> next;
	}
	free(arr);
}

void	complex_sort(t_stack *a, t_stack *b, t_runtime *rt)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	normalize_stack(a);
	max_bits = get_max_bits(a -> size - 1);
	i = 0;
	while (i < max_bits)
	{
		size = a -> size;
		j = 0;
		while (j < size)
		{
			if (((a -> top -> data >> i) & 1) == 0)
				pb(a, b, rt);
			else
				ra(a, rt);
			j++;
		}
		while (b -> size > 0)
			pa(a, b, rt);
		i++;
	}
}
