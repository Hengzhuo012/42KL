/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namak <namak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 11:30:09 by namak             #+#    #+#             */
/*   Updated: 2026/09/04 10:05:36 by namak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack);
	last->next = first;
}

void	ra(t_list **a, t_list **b, t_flag *flags, t_opt *opt)
{
	(void)b;
	rotate(a);
	if (flags->bench)
		opt->ra++;
	write(1, "ra\n", 3);
}

void	rb(t_list **a, t_list **b, t_flag *flags, t_opt *opt)
{
	(void)a;
	rotate(b);
	if (flags->bench)
		opt->rb++;
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, t_flag *flags, t_opt *opt)
{
	rotate(b);
	rotate(a);
	if (flags->bench)
		opt->rr++;
	write(1, "rr\n", 3);
}
