/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:34:53 by nelali            #+#    #+#             */
/*   Updated: 2025/12/11 17:37:38 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	count;
	t_list	*i;

	if (lst == NULL)
		return (0);
	count = 0;
	i = lst;
	while (i != NULL)
	{
		count++;
		i = i -> next;
	}
	return (count);
}
