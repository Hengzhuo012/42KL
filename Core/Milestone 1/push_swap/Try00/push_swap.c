/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namak <namak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:55:29 by zheng             #+#    #+#             */
/*   Updated: 2026/09/07 09:09:38 by namak            ###   ########.fr       */
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
			ft_lstclear(stack, del_nothing);
			return (0);
		}
		ft_lstadd_back(stack, new_node);
		i++;
	}
	return (1);
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

static int	init_and_build_stack(char **args, t_flag *flags, t_list **stack)
{
	int	i;

	init_t_flag(flags);
	i = check_inputs(args, flags);
	if (i <= 0)
		return (0);
	*stack = NULL;
	if (!add_num_to_stack(stack, args, i))
		return (0);
	return (1);
}

static void	run_push_swap(t_flag *flags, t_list **stack)
{
	t_opt	opt;
	double	disorder;

	init_t_opt(&opt);
	disorder = compute_disorder(*stack);
	set_to_ranks(*stack);
	determine_and_proceed(flags, stack, &opt, disorder);
	if (flags->bench)
		print_bench(flags, &opt, disorder);
}

int	main(int argc, char **argv)
{
	t_flag	flags;
	t_list	*stack;
	char	**args;

	if (argc < 2)
		return (0);
	args = create_args(argc, argv);
	if (!args)
		return (allocation_error());
	if (!init_and_build_stack(args, &flags, &stack))
	{
		free_args(args);
		return (allocation_error());
	}
	run_push_swap(&flags, &stack);
	ft_lstclear(&stack, del_nothing);
	free_args(args);
	return (0);
}
