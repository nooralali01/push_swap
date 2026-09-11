/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salfaraw <salfaraw@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:03:59 by salfaraw          #+#    #+#             */
/*   Updated: 2026/02/07 15:09:23 by salfaraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	validate_flags(t_runtime *rt)
{
	int	count;

	count = rt->flags.simple
		+ rt->flags.medium
		+ rt->flags.complex
		+ rt->flags.adaptive;
	if (count > 1)
		error_exit();
	if (count == 0)
		rt->flags.adaptive = 1;
}

static int	is_flag(char *s)
{
	if (!ft_strcmp(s, "--simple"))
		return (1);
	if (!ft_strcmp(s, "--medium"))
		return (1);
	if (!ft_strcmp(s, "--complex"))
		return (1);
	if (!ft_strcmp(s, "--adaptive"))
		return (1);
	if (!ft_strcmp(s, "--bench"))
		return (1);
	return (0);
}

int	handle_flags(int argc, char **argv, t_runtime *rt, int *i)
{
	rt->flags.simple = 0;
	rt->flags.medium = 0;
	rt->flags.complex = 0;
	rt->flags.adaptive = 0;
	rt->bench = 0;
	while (*i < argc && is_flag(argv[*i]))
	{
		if (!ft_strcmp(argv[*i], "--simple"))
			rt->flags.simple = 1;
		else if (!ft_strcmp(argv[*i], "--medium"))
			rt->flags.medium = 1;
		else if (!ft_strcmp(argv[*i], "--complex"))
			rt->flags.complex = 1;
		else if (!ft_strcmp(argv[*i], "--adaptive"))
			rt->flags.adaptive = 1;
		else if (!ft_strcmp(argv[*i], "--bench"))
			rt->bench = 1;
		else
			error_exit();
		(*i)++;
	}
	validate_flags(rt);
	return (*i);
}
