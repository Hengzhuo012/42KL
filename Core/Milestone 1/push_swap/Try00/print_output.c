/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:23:04 by zheng             #+#    #+#             */
/*   Updated: 2026/08/25 01:11:31 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

static void	print_number(int number)
{
	char	*number_str;

	number_str = ft_itoa(number);
	if (!number_str)
		return ;
	write(2, number_str, ft_strlen(number_str));
	free(number_str);
}

static void	print_strategy(t_flag *flags, double disorder)
{
	if (flags->strat == 's')
		write(2, "Simple / O(n^2)", ft_strlen("Simple / O(n^2)"));
	else if (flags->strat == 'm')
		write(2, "Medium / O(n*sqrt(n))",
			ft_strlen("Medium / O(n*sqrt(n))"));
	else if (flags->strat == 'c')
		write(2, "Complex / O(n log n)", ft_strlen("Complex / O(n log n)"));
	else if (disorder < 0.2)
		write(2, "Simple / O(n^2)", ft_strlen("Simple / O(n^2)"));
	else if (disorder < 0.5)
		write(2, "Medium / O(n*sqrt(n))",
			ft_strlen("Medium / O(n*sqrt(n))"));
	else
		write(2, "Complex / O(n log n)", ft_strlen("Complex / O(n log n)"));
}

static void	print_opt(t_opt *opt)
{
	write(2, "\n[bench] sa: ", ft_strlen("\n[bench] sa: "));
	print_number(opt->sa);
	write(2, " sb: ", ft_strlen(" sb: "));
	print_number(opt->sb);
	write(2, " ss: ", ft_strlen(" ss: "));
	print_number(opt->ss);
	write(2, " pa: ", ft_strlen(" pa: "));
	print_number(opt->pa);
	write(2, " pb: ", ft_strlen(" pb: "));
	print_number(opt->pb);
	write(2, "\n[bench] ra: ", ft_strlen("\n[bench] ra: "));
	print_number(opt->ra);
	write(2, " rb: ", ft_strlen(" rb: "));
	print_number(opt->rb);
	write(2, " rr: ", ft_strlen(" rr: "));
	print_number(opt->rr);
	write(2, " rra: ", ft_strlen(" rra: "));
	print_number(opt->rra);
	write(2, " rrb: ", ft_strlen(" rrb: "));
	print_number(opt->rrb);
	write(2, " rrr: ", ft_strlen(" rrr: "));
	print_number(opt->rrr);
	write(2, "\n", ft_strlen("\n"));
}

void	print_bench(t_flag *flags, t_opt *opt, double disorder)
{
	int	disorder_hundredths;

	disorder_hundredths = (int)(disorder * 10000.0 + 0.5);
	write(2, "[bench] disorder: ", ft_strlen("[bench] disorder: "));
	print_number(disorder_hundredths / 100);
	write(2, ".", 1);
	if (disorder_hundredths % 100 < 10)
		write(2, "0", 1);
	print_number(disorder_hundredths % 100);
	write(2, "%\n[bench] strategy: ", ft_strlen("%\n[bench] strategy: "));
	print_strategy(flags, disorder);
	write(2, "\n[bench] total_ops: ", ft_strlen("\n[bench] total_ops: "));
	print_number(opt->sa + opt->sb + opt->ss + opt->pa + opt->pb
		+ opt->ra + opt->rb + opt->rr + opt->rra + opt->rrb + opt->rrr);
	print_opt(opt);
}
