/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salfaraw <salfaraw@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:13:28 by salfaraw          #+#    #+#             */
/*   Updated: 2026/02/07 15:13:35 by salfaraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_node	*create_node(int value, t_stack *a)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = value;
	new->next = NULL;
	new->prev = a->bottom;
	return (new);
}

static void	push_bottom(t_stack *a, t_node *new)
{
	if (a->size == 0)
	{
		a->top = new;
		a->bottom = new;
	}
	else
	{
		a->bottom->next = new;
		a->bottom = new;
	}
	a->size++;
}

int	fill_stack(t_stack *a, int *arr, int count)
{
	int		i;
	t_node	*new;

	i = 0;
	while (i < count)
	{
		new = create_node(arr[i], a);
		if (!new)
		{
			stack_free(a);
			return (0);
		}
		push_bottom(a, new);
		i++;
	}
	return (1);
}

static int	validate_numbers(char **words, int *num, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!is_number(words[i]))
			return (0);
		if (!string_to_int(words[i], &num[i]))
			return (0);
		i++;
	}
	if (has_duplicates(num, count))
		return (0);
	return (1);
}

int	read_numbers(t_stack *a, t_stack *b, char **argv)
{
	char	**words;
	int		*num;
	int		count;

	(void)b;
	if (!argv[0])
		return (1);
	words = split_words(argv);
	if (!words)
		return (0);
	count = 0;
	while (words[count])
		count++;
	num = malloc(sizeof(int) * count);
	if (!num)
		return (free_words(words), 0);
	if (!validate_numbers(words, num, count))
		return (free_words(words), free(num), 0);
	if (!fill_stack(a, num, count))
		return (free_words(words), free(num), 0);
	free_words(words);
	free(num);
	return (1);
}
