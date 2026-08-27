/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:55:29 by zheng             #+#    #+#             */
/*   Updated: 2026/08/27 14:07:03 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_num_to_stack(t_list **stack, char **argv, int i)
{
	t_list	*new_node;

	while (argv[i])
	{
		new_node = ft_lstnew((void *)(long)ft_atoi(argv[i]));
		if (!new_node)
		{
			ft_lstclear(stack, NULL);
			return (0);
		}
		ft_lstadd_back(stack, new_node);
		i++;
	}
	return (1);
}

static int	allocation_error(void)
{
	print_error();
	return (1);
}

static double	compute_disorder(t_list *stack)
{
	t_list	*stack_cpy;
	int		mistakes;
	int		pairs;

	mistakes = 0;
	pairs = 0;
	while (stack)
	{
		stack_cpy = stack->next;
		while (stack_cpy)
		{
			pairs++;
			if ((long int)stack->content > (long int)stack_cpy->content)
				mistakes++;
			stack_cpy = stack_cpy->next;
		}
		stack = stack->next;
	}
	if (pairs == 0)
		return (0);
	return ((double)mistakes / pairs);
}

static void	determine_and_proceed(t_flag *flags, t_list **stack,
t_opt *opt, double disorder)
{
	if (flags->strat == 'a')
	{
		if (disorder < 0.2)
			simple_sort(flags, stack, opt);
		else if (disorder < 0.7)
			medium_sort(flags, stack, opt);
		else
			complex_sort(flags, stack, opt);
	}
	else if (flags->strat == 's')
		simple_sort(flags, stack, opt);
	else if (flags->strat == 'm')
		medium_sort(flags, stack, opt);
	else if (flags->strat == 'c')
		complex_sort(flags, stack, opt);
}

int	main(int argc, char **argv)
{
	t_flag	flags;
	t_list	*stack;
	t_opt	opt;
	double	disorder;
	int		i;

	if (argc < 2)
		return (0);
	init_t_flag(&flags);
	i = check_inputs(argv, &flags);
	if (i <= 0)
		return (allocation_error());
	stack = NULL;
	init_t_opt(&opt);
	if (!add_num_to_stack(&stack, argv, i))
		return (allocation_error());
	disorder = compute_disorder(stack);
	set_to_ranks(stack);
	determine_and_proceed(&flags, &stack, &opt, disorder);
	if (flags.bench)
		print_bench(&flags, &opt, disorder);
	ft_lstclear(&stack, NULL);
	return (0);
}
