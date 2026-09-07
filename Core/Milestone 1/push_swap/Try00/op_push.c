/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namak <namak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 12:16:36 by namak             #+#    #+#             */
/*   Updated: 2026/09/04 10:04:59 by namak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b, t_flag *flags, t_opt *opt)
{
	t_list	*first;

	if (!a || !b || *b == NULL)
		return ;
	first = *b;
	*b = first->next;
	first->next = *a;
	*a = first;
	if (flags->bench)
		opt->pa++;
	else
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b, t_flag *flags, t_opt *opt)
{
	t_list	*first;

	if (!b || !a || *a == NULL)
		return ;
	first = *a;
	*a = first->next;
	first->next = *b;
	*b = first;
	if (flags->bench)
		opt->pb++;
	else
		write(1, "pb\n", 3);
}
