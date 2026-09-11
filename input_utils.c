/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:31:41 by nelali            #+#    #+#             */
/*   Updated: 2026/02/07 15:14:56 by salfaraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

static int	check_overflow(long result, int digit, int sign)
{
	long	limit;

	if (sign == 1)
		limit = INT_MAX;
	else
		limit = -(long)INT_MIN;
	if (result > (limit - digit) / 10)
		return (0);
	return (1);
}

int	string_to_int(char *str, int *num)
{
	long	result;
	int		i;
	int		sign;
	int		digit;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		if (!check_overflow(result, digit, sign))
			return (0);
		result = result * 10 + digit;
		i++;
	}
	*num = (int)(result * sign);
	return (1);
}

int	has_duplicates(int *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_words(char **words)
{
	int	i;

	if (words == NULL)
		return ;
	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words);
}
