/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:47:06 by zheng             #+#    #+#             */
/*   Updated: 2026/08/28 01:31:57 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_rank)
{
	int	max_bits;

	max_bits = 0;
	while (max_rank >> max_bits)
		max_bits++;
	return (max_bits);
}

static void	complex_sort_helper(t_flag *flags,
t_list **stack_a, t_list **stack_b, t_opt *opt)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((int)(long)(*stack_a)->content >> i) & 1)
				ra(stack_a, stack_b, flags, opt);
			else
				pb(stack_a, stack_b, flags, opt);
		}
		while (*stack_b)
			pa(stack_a, stack_b, flags, opt);
		i++;
	}
}

void	complex_sort(t_flag *flags, t_list **stack_a, t_opt *opt)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (is_sorted(*stack_a))
		return ;
	complex_sort_helper(flags, stack_a, &stack_b, opt);
}
