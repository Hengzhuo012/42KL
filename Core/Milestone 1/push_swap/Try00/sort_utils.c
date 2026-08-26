/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:49:37 by zheng             #+#    #+#             */
/*   Updated: 2026/08/20 16:58:48 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	medium_sqrt(int n)
{
	int	r;

	if (n <= 0)
		return (0);
	r = 1;
	while (r <= n / r)
	{
		if (r * r == n)
			return (r);
		r++;
	}
	return (r - 1);
}

int	get_rank(t_list *stack, t_list *bucket, int val)
{
	int	rank;

	rank = 0;
	while (stack)
	{
		if ((int)(long)stack->content < val)
			rank++;
		stack = stack->next;
	}
	while (bucket)
	{
		if ((int)(long)bucket->content < val)
			rank++;
		bucket = bucket->next;
	}
	return (rank);
}

int	get_max_pos(t_list *bucket)
{
	int	max;
	int	pos;
	int	max_pos;

	max = (int)(long)bucket->content;
	pos = 0;
	max_pos = 0;
	while (bucket)
	{
		if ((int)(long)bucket->content > max)
		{
			max = (int)(long)bucket->content;
			max_pos = pos;
		}
		pos++;
		bucket = bucket->next;
	}
	return (max_pos);
}
