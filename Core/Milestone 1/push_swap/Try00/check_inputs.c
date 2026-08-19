/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 11:59:49 by zheng             #+#    #+#             */
/*   Updated: 2026/08/19 15:20:48 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_flag(char *str, t_flag *flags)
{
	if (!str)
		return (0);
	if (ft_strncmp(str, "--simple", ft_strlen("--simple") + 1) == 0)
		flags->strat = 's';
	else if (ft_strncmp(str, "--medium", ft_strlen("--medium") + 1) == 0)
		flags->strat = 'm';
	else if (ft_strncmp(str, "--complex", ft_strlen("--complex") + 1) == 0)
		flags->strat = 'c';
	else if (ft_strncmp(str, "--bench", ft_strlen("--bench") + 1) == 0)
		flags->bench = 'b';
	else
		return (0);
	return (1);
}

static int	check_duplicate(char **argv, int i)
{
	int	j;

	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_digits_set_n(char **argv, int i, int j,
long long int *n)
{
	while (argv[i][j])
	{
		if (!ft_isdigit(argv[i][j]))
			return (0);
		*n = (*n * 10) + (argv[i][j] - '0');
		if (*n > 2147483648LL)
			return (0);
		j++;
	}
	return (1);
}

static int	check_values(char **argv, int i)
{
	long long int	n;
	int				is_negative;
	int				j;

	while (argv[i])
	{
		is_negative = 1;
		n = 0;
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
		{
			if (argv[i][j] == '-')
				is_negative = -1;
			j++;
		}
		if (!argv[i][j])
			return (0);
		if (!check_digits_set_n(argv, i, j, &n))
			return (0);
		if ((n * is_negative) < -2147483648LL
			|| (n * is_negative) > 2147483647LL)
			return (0);
		i++;
	}
	return (1);
}


// return -1 if no number inputs, 0 if failed, index of the 1st number if pass
int	check_inputs(char **argv, t_flag *flags, int *i)
{
	int	i;

	i = 1;
	while (check_flag(argv[i], flags))
		i++;
	if (!argv[i])
		return (-1);
	if (check_values(argv, i) && check_duplicate(argv, i))
		return (i);
	return (0);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	printf("%d", check_values(argv, 1));
// 	return (0);
// }