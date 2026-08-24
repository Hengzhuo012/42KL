/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 11:30:09 by namak             #+#    #+#             */
/*   Updated: 2026/08/25 00:59:14 by zheng            ###   ########.fr       */
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
	else
		write(1, "ra\n", 3);
}

void	rb(t_list **a, t_list **b, t_flag *flags, t_opt *opt)
{
	(void)a;
	rotate(b);
	if (flags->bench)
		opt->rb++;
	else
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, t_flag *flags, t_opt *opt)
{
	rotate(b);
	rotate(a);
	if (flags->bench)
		opt->rr++;
	else
		write(1, "rr\n", 3);
}
