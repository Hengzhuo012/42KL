/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 21:37:22 by zheng             #+#    #+#             */
/*   Updated: 2026/08/20 00:42:45 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
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

static void	add_stack_to_bucket(t_list **stack, t_list **bucket,
t_flag *flags, t_opt *opt)
{
	int	bucket_size;
	int	lower;
	int	upper;

	bucket_size = ft_sqrt(ft_lstsize(*stack));
	lower = 0;
	upper = bucket_size;
	while (*stack)
	{

		if ((int)(*stack)->content <= upper)
		{
			pb(stack, bucket, flags, opt);
			if ((int)(*bucket)->content < lower + (bucket_size / 2))
				rb(stack, bucket, flags, opt);
			lower++;
			upper++;
		}
		else
			ra(stack, bucket, flags, opt);
	}
}

/* Helper function to find the index of the target rank in Stack B */
static int	get_max_pos(t_list *bucket, int target)
{
	int	pos;

	pos = 0;
	while (bucket)
	{
		if ((int)(long)bucket->content == target)
			return (pos);
		pos++;
		bucket = bucket->next;
	}
	return (0);
}

/* Implemented the missing Phase 2 logic to return items to Stack A */
static void	sort_bucket_add_to_stack(t_list **stack, t_list **bucket,
				t_flag *flags, t_opt *opt)
{
	int	size;
	int	pos;
	int	target;

	target = ft_lstsize(*bucket) - 1;
	while (*bucket)
	{
		size = ft_lstsize(*bucket);
		pos = get_max_pos(*bucket, target);
		if (pos <= size / 2)
		{
			while ((int)(long)(*bucket)->content != target)
				rb(stack, bucket, flags, opt);
		}
		else
		{
			while ((int)(long)(*bucket)->content != target)
				rrb(stack, bucket, flags, opt);
		}
		pa(stack, bucket, flags, opt);
		target--;
	}
}

void	medium_sort(t_flag *flags, t_list **stack, t_opt *opt)
{
	t_list	*bucket;

	bucket = NULL;
	add_stack_to_bucket(stack, &bucket, flags, opt);
	sort_bucket_add_to_stack(stack, &bucket, flags, opt);
}
