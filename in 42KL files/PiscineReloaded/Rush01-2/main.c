/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 10:52:47 by zheng             #+#    #+#             */
/*   Updated: 2026/07/23 15:54:08 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	solve_check(char *arr, char *argv, int size, int row)

//row set as 0 at start
int	solve(char *arr, char *argv, int size, int row)
{
	char	*str_row;

	init_first_permutation(arr, row, size);
	str_row = ft_str_row(row, arr, size);
	while (1)
	{
		if (check_left_right(str_row, size, argv, row)
			&& check_element(arr, size, row))
		{
			if (row == size * (size - 1))
			{
				free(str_row);
				return (check_top_bot(arr, size, argv));
			}
			if (solve(arr, argv, size, row + size))
			{
				free(str_row);
				return (1);
			}
		}
		if (is_last_comb(str_row, size))
			break ;
		ft_next_permutation(str_row, size);
		set_row(str_row, arr, row, size);
	}
	reset_row(arr, row, size);
	free(str_row);
	return (0);
}

int	ft_size(char *str)
{
	int	len;

	len = ft_strlen(str);
	if ((len + 1) % 8 != 0)
		return (0);
	return ((len + 1) / 8);
}

int	check(char *argv)
{
	int	i;

	i = 0;
	while (i < ft_strlen(argv))
	{
		if (i % 2 && argv[i] != ' ')
			return (0);
		if (!(i % 2) && argv[i] < '0' && argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*arr;
	int		size;
	int		i;

	if (argc == 2)
	{
		size = ft_size(argv[1]);
		if (size && check(argv[1]))
		{
			arr = malloc((size * size) * sizeof(char));
			i = 0;
			while (i < size * size)
				arr[i++] = '0';
			if (solve(arr, argv[1], size, 0))
				ft_print(arr, size);
			else
				ft_error();
			free(arr);
		}
		else
			ft_error();
	}
	else
		ft_error();
	return (1);
}
