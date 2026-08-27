/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 19:13:35 by zheng             #+#    #+#             */
/*   Updated: 2026/08/24 14:56:52 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_content(void *content)
{
	(void)content;
}

void	init_t_opt(t_opt *opt)
{
	opt->sa = 0;
	opt->sb = 0;
	opt->ss = 0;
	opt->pa = 0;
	opt->pb = 0;
	opt->ra = 0;
	opt->rb = 0;
	opt->rr = 0;
	opt->rra = 0;
	opt->rrb = 0;
	opt->rrr = 0;
}

void	init_t_flag(t_flag *flags)
{
	flags->strat = 'a';
	flags->bench = 0;
}
