/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:01:07 by nelali            #+#    #+#             */
/*   Updated: 2025/12/16 17:27:21 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

static char	*get_word(const char *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

static void	free_array(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	wc;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	wc = word_count(s, c);
	split = malloc(sizeof(char *) * (wc + 1));
	if (split == NULL)
		return (NULL);
	while (s[i] != '\0' && j < wc)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		split[j] = get_word(&s[i], c);
		if (split[j] == NULL)
			return (free_array(split), NULL);
		i += ft_strlen(split[j]);
		j++;
	}
	split[j] = NULL;
	return (split);
}
