/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namak <namak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 11:46:13 by namak             #+#    #+#             */
/*   Updated: 2026/09/04 10:04:18 by namak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*sec_last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	sec_last = *stack;
	while (sec_last->next->next != NULL)
		sec_last = sec_last->next;
	last = sec_last->next;
	sec_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_list **a, t_list **b, t_flag *flags, t_opt *opt)
{
	(void)b;
	reverse_rotate(a);
	if (flags->bench)
		opt->rra++;
	else
		write(1, "rra\n", 4);
}

void	rrb(t_list **a, t_list **b, t_flag *flags, t_opt *opt)
{
	(void)a;
	reverse_rotate(b);
	if (flags->bench)
		opt->rrb++;
	else
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, t_flag *flags, t_opt *opt)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (flags->bench)
		opt->rrr++;
	else
		write(1, "rrr\n", 4);
}

/*
void	rra(t_list **a)
{

	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
*/
