/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:55:29 by zheng             #+#    #+#             */
/*   Updated: 2026/08/14 15:33:59 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_flag(char *str, t_flag *flags)
{
	flags->strat = 'a';
	if (str == "--simple")
		flags->strat = 's';
	else if (str == "--medium")
		flags->strat = 'm';
	else if (str == "--complex")
		flags->strat = 'c';
	else if (str == "--bench")
		flags->bench = 'b';
	else
		return (0);
	return (1);
}

static int	check_values(char **argv, int i)
{

}

static void	print_error(void)
{
	ft_printf("Error\n");
}

int	main(int argc, char **argv)
{
	t_flag	flags;
	int		i;

	i = 1;
	while (check_flag(argv[i], &flags))
		i++;
	if (!check_values(argv, i))
		return (print_error());
}