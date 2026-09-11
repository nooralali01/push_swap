/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:49:19 by nelali            #+#    #+#             */
/*   Updated: 2026/01/27 16:56:43 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char **argv)
{
	char	**tmp;
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp || !tmp[0])
		{
			free_words(tmp);
			return (-1);
		}
		j = 0;
		while (tmp[j])
			j++;
		count += j;
		free_words(tmp);
		i++;
	}
	return (count);
}

static void	copy_words(char **dst, char **argv)
{
	char	**temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (argv[i])
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
			return ;
		j = 0;
		while (temp[j])
			dst[k++] = temp[j++];
		free(temp);
		i++;
	}
}

char	**split_words(char **argv)
{
	char	**words;
	int		count;

	count = count_words(argv);
	if (count <= 0)
		return (NULL);
	words = malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	copy_words(words, argv);
	words[count] = NULL;
	return (words);
}
