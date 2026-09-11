/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:40:39 by nelali            #+#    #+#             */
/*   Updated: 2025/12/11 17:43:03 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*i;

	if (lst == NULL)
		return (NULL);
	i = lst;
	while (i -> next != NULL)
		i = i -> next;
	return (i);
}
