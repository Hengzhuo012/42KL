/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 21:37:22 by zheng             #+#    #+#             */
/*   Updated: 2026/08/20 16:59:09 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_stack_to_bucket(t_list **stack, t_list **bucket,
t_flag *flags, t_opt *opt)
{
	int	bucket_size;
	int	lower;
	int	upper;
	int	rank;

	bucket_size = medium_sqrt(ft_lstsize(*stack));
	lower = 0;
	upper = bucket_size;
	while (*stack)
	{
		rank = get_rank(*stack, *bucket, (int)(long)(*stack)->content);
		if (rank <= upper)
		{
			pb(stack, bucket, flags, opt);
			rank = get_rank(*stack, *bucket, (int)(long)(*bucket)->content);
			if (ft_lstsize(*bucket) > 1
				&& rank < lower + (bucket_size / 2))
				rb(stack, bucket, flags, opt);
			lower++;
			upper++;
		}
		else
			ra(stack, bucket, flags, opt);
	}
}

static void	sort_bucket_add_to_stack(t_list **stack, t_list **bucket,
t_flag *flags, t_opt *opt)
{
	int	size;
	int	pos;
	int	i;

	while (*bucket)
	{
		size = ft_lstsize(*bucket);
		pos = get_max_pos(*bucket);
		i = 0;
		if (pos <= size / 2)
		{
			while (i++ < pos)
				rb(stack, bucket, flags, opt);
		}
		else
		{
			while (i++ < size - pos)
				rrb(stack, bucket, flags, opt);
		}
		pa(stack, bucket, flags, opt);
	}
}

void	medium_sort(t_flag *flags, t_list **stack, t_opt *opt)
{
	t_list	*bucket;

	bucket = NULL;
	add_stack_to_bucket(stack, &bucket, flags, opt);
	sort_bucket_add_to_stack(stack, &bucket, flags, opt);
}
