/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namak <namak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 11:23:57 by namak             #+#    #+#             */
/*   Updated: 2026/09/07 15:08:20 by namak            ###   ########.fr       */
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

void	sa_b(t_list **a, t_list **b)
{
	(void)b;
	swap(a);
}

void	sb_b(t_list **a, t_list **b)
{
	(void)a;
	swap(b);
}

void	ss_b(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}
