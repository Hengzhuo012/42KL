/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:14:02 by namak             #+#    #+#             */
/*   Updated: 2026/09/07 15:47:26 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

static int	init_and_build_stack(char **args, t_list **stack)
{
	int	i;

	i = check_inputs_bonus(args);
	if (i <= 0)
		return (0);
	*stack = NULL;
	if (!add_num_to_stack(stack, args, i))
		return (0);
	return (1);
}

static int	apply_operation(char *op, t_list **a, t_list **b)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		sa_b(a, b);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb_b(a, b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss_b(a, b);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		pa_b(a, b);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb_b(a, b);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra_b(a, b);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb_b(a, b);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr_b(a, b);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra_b(a, b);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb_b(a, b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr_b(a, b);
	else
		return (0);
	return (1);
}

static void	check_sorted(t_list **a, t_list **b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		if (!apply_operation(op, a, b))
		{
			free(op);
			ft_printf("Error\n");
			return ;
		}
		free(op);
		op = get_next_line(0);
	}
	if (is_sorted(*a) && !(*b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	char	**args;
	t_list	*stack;
	t_list	*b;

	if (argc < 2)
		return (0);
	args = create_args(argc, argv);
	if (!args)
		return (allocation_error());
	if (!init_and_build_stack(args, &stack))
	{
		free_args(args);
		return (allocation_error());
	}
	b = NULL;
	check_sorted(&stack, &b);
	ft_lstclear(&stack, del_nothing);
	ft_lstclear(&b, del_nothing);
	free_args(args);
	return (0);
}
