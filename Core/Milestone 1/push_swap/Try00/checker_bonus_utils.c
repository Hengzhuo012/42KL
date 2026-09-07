/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namak <namak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 15:47:09 by zheng             #+#    #+#             */
/*   Updated: 2026/09/07 15:53:00 by namak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if ((int)(long)stack->content
			> (int)(long)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
