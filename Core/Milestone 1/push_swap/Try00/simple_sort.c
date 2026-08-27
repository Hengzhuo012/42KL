/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:25:58 by namak             #+#    #+#             */
/*   Updated: 2026/08/28 01:47:03 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_pos(t_list *stack)
{
	int	min_pos;
	int	current_pos;
	int	min_val;

	min_pos = 0;
	current_pos = 0;
	min_val = 2147483647;
	while (stack)
	{
		if ((int)(long) stack->content < min_val)
		{
			min_val = (int)(long)stack->content;
			min_pos = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (min_pos);
}

static void	sort_two(t_list **stack, t_list **b, t_flag *flags, t_opt *opt)
{
	if ((int)(long)(*stack)->content > (int)(long)(*stack)->next->content)
		sa(stack, b, flags, opt);
}

static void	sort_three(t_list **stack, t_list **b, t_flag *flags, t_opt *opt)
{
	int	first;
	int	second;
	int	third;

	first = (int)(long)(*stack)->content;
	second = (int)(long)(*stack)->next->content;
	third = (int)(long)(*stack)->next->next->content;
	if (first > second && second > third)
	{
		sa(stack, b, flags, opt);
		rra(stack, b, flags, opt);
	}
	else if (first > second && first > third)
		ra(stack, b, flags, opt);
	else if (first > second)
		sa(stack, b, flags, opt);
	else if (second > third && first > third)
		rra(stack, b, flags, opt);
	else if (second > third)
	{
		sa(stack, b, flags, opt);
		ra(stack, b, flags, opt);
	}
}

static void	push_min_to_b(t_list **a, t_list **b, t_flag *flags, t_opt *opt)
{
	int	size;
	int	min_pos;

	size = ft_lstsize(*a);
	min_pos = get_min_pos(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a, b, flags, opt);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos-- > 0)
			rra(a, b, flags, opt);
	}
	pb(a, b, flags, opt);
}

void	simple_sort(t_flag *flags, t_list **a, t_opt *opt)
{
	int		size;
	t_list	*b;

	if (is_sorted(a))
		return ;
	size = ft_lstsize(*a);
	b = NULL;
	while (size-- > 3)
	{
		push_min_to_b(a, &b, flags, opt);
		if (is_sorted(*a))
			break ;
	}
	if (size == 2)
		sort_two(a, &b, flags, opt);
	else if (size == 3)
		sort_three(a, &b, flags, opt);
	while (b)
		pa(a, &b, flags, opt);
}
