/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namak <namak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 11:46:13 by namak             #+#    #+#             */
/*   Updated: 2026/09/07 15:08:13 by namak            ###   ########.fr       */
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

void	rra_b(t_list **a, t_list **b)
{
	(void)b;
	reverse_rotate(a);
}

void	rrb_b(t_list **a, t_list **b)
{
	(void)a;
	reverse_rotate(b);
}

void	rrr_b(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
