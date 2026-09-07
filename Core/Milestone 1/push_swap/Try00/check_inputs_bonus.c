/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 11:59:49 by zheng             #+#    #+#             */
/*   Updated: 2026/09/07 15:46:46 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
int	check_inputs_bonus(char **argv)
{
	int	i;

	i = 1;
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
// 	printf("%d", check_inputs_bonus(argv));
// 	return (0);
// }
