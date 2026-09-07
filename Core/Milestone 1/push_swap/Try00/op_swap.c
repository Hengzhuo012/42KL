/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namak <namak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 11:23:57 by namak             #+#    #+#             */
/*   Updated: 2026/09/04 10:04:30 by namak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	temp = first->next;
	first->next = temp->next;
	temp->next = first;
	*stack = temp;
}

void	sa(t_list **a, t_list **b, t_flag *flags, t_opt *opt)
{
	(void)b;
	swap(a);
	if (flags->bench)
		opt->sa++;
	else
		write(1, "sa\n", 3);
}

void	sb(t_list **a, t_list **b, t_flag *flags, t_opt *opt)
{
	(void)a;
	swap(b);
	if (flags->bench)
		opt->sb++;
	else
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, t_flag *flags, t_opt *opt)
{
	swap(a);
	swap(b);
	if (flags->bench)
		opt->ss++;
	else
		write(1, "ss\n", 3);
}

/*
void	sa(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap (a);
	swap (b);
	write(1, "ss\n", 3);
}
*/
