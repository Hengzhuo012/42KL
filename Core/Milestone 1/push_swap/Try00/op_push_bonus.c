/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namak <namak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 12:16:36 by namak             #+#    #+#             */
/*   Updated: 2026/09/07 15:07:57 by namak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_b(t_list **a, t_list **b)
{
	t_list	*first;

	if (!a || !b || *b == NULL)
		return ;
	first = *b;
	*b = first->next;
	first->next = *a;
	*a = first;
}

void	pb_b(t_list **a, t_list **b)
{
	t_list	*first;

	if (!b || !a || *a == NULL)
		return ;
	first = *a;
	*a = first->next;
	first->next = *b;
	*b = first;
}
