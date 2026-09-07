/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 11:30:09 by namak             #+#    #+#             */
/*   Updated: 2026/09/07 15:48:16 by zheng            ###   ########.fr       */
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

void	ra_b(t_list **a, t_list **b)
{
	(void)b;
	rotate(a);
}

void	rb_b(t_list **a, t_list **b)
{
	(void)a;
	rotate(b);
}

void	rr_b(t_list **a, t_list **b)
{
	rotate(b);
	rotate(a);
}
