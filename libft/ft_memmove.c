/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:06:14 by nelali            #+#    #+#             */
/*   Updated: 2025/12/08 16:24:46 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	copy_forward(unsigned char *d, unsigned char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

static void	copy_backward(unsigned char *d, unsigned char *s, size_t n)
{
	while (n > 0)
	{
		n--;
		d[n] = s[n];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	unsigned char		*ptr2;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr = (unsigned char *) dest;
	ptr2 = (unsigned char *) src;
	if (ptr > ptr2)
	{
		copy_backward(ptr, ptr2, n);
	}
	else
	{
		copy_forward(ptr, ptr2, n);
	}
	return (dest);
}
