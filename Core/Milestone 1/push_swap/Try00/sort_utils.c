/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:49:37 by zheng             #+#    #+#             */
/*   Updated: 2026/08/27 13:33:29 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*copy_stack(t_list *stack)
{
	t_list	*copy;
	t_list	*new_node;

	copy = NULL;
	while (stack)
	{
		new_node = ft_lstnew(stack->content);
		if (!new_node)
		{
			ft_lstclear(&copy, NULL);
			return (NULL);
		}
		ft_lstadd_back(&copy, new_node);
		stack = stack->next;
	}
	return (copy);
}

void	set_to_ranks(t_list *stack)
{
	t_list	*original;

	original = copy_stack(stack);
	if (!original && stack)
		return ;
	while (stack)
	{
		stack->content = (void *)(long)get_rank(original, NULL,
				(int)(long)stack->content);
		stack = stack->next;
	}
	ft_lstclear(&original, NULL);
}

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
