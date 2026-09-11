/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:15:58 by nelali            #+#    #+#             */
/*   Updated: 2025/12/08 17:22:44 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while ((haystack[i + j] == needle[j])
			&& ((i + j) < len)
			&& needle[j] != '\0')
			j++;
		if (needle[j] == '\0')
			return ((char *) &haystack[i]);
		i++;
	}
	return (NULL);
}
