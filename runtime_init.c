/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelali <nelali@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:27:07 by nelali            #+#    #+#             */
/*   Updated: 2026/02/07 15:27:15 by nelali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_runtime(t_runtime *rt)
{
	rt->bench = 0;
	rt->disorder = 0.0;
	rt->ops.total = 0;
	rt->ops.sa = 0;
	rt->ops.sb = 0;
	rt->ops.ss = 0;
	rt->ops.pa = 0;
	rt->ops.pb = 0;
	rt->ops.ra = 0;
	rt->ops.rb = 0;
	rt->ops.rr = 0;
	rt->ops.rra = 0;
	rt->ops.rrb = 0;
	rt->ops.rrr = 0;
	rt->flags.simple = 0;
	rt->flags.medium = 0;
	rt->flags.complex = 0;
	rt->flags.adaptive = 0;
}
