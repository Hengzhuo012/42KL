/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:47:06 by zheng             #+#    #+#             */
/*   Updated: 2026/08/27 00:44:02 by zheng            ###   ########.fr       */
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

void	complex_sort(t_flag *flags, t_list **stack_a, t_opt *opt)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;
	t_list	*stack_b;

	size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(size - 1);
	stack_b = NULL;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if ((get_rank(*stack_a, stack_b,
						(int)(long)(*stack_a)->content) >> i) & 1)
				ra(stack_a, &stack_b, flags, opt);
			else
				pb(stack_a, &stack_b, flags, opt);
		}
		while (stack_b)
			pa(stack_a, &stack_b, flags, opt);
		i++;
	}
}
