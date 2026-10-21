/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 10:52:47 by zheng             #+#    #+#             */
/*   Updated: 2026/07/23 15:37:43 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	check_left_right(char *str_row, int size, char *argv, int row);
int	check_top_bot(char *array, int size, char *argv);
int	check_element(char *array, int size, int row);
int	ft_next_permutation(char *out, int size);
int	is_last_comb(char *arr, int size, int row);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_str_row(int	row, char *arr, int size)
{
	int		i;
	char	*str_row;

	i = 0;
	str_row = malloc(size * sizeof(char));
	while (i < size)
	{
		str_row[i] = arr[row + i];
		i++;
	}
	return (str_row);
}

void	init_first_permutation(char *arr, int row, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[row + i] = i + '1';
		i++;
	}
}

void	reset_row(char *arr, int row, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[row + i] = '0';
		i++;
	}
}

void	set_row(char *str_row, char *arr, int row, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[row + i] = str_row[i];
		i++;
	}
}

void	set_last_row(char *arr, int size)
{
	int	element;
	int check;
	int	col;
	int	i;

	col = 0;
	while (col < size)
	{
		element = 1;
		check = 1;
		while (check)
		{
			check = 0;
			i = 0;
			while (i <= size * (size - 1))
			{
				if (element == arr[i + col])
				{
					element++;
					check = 1;
				}
				i += size;
			}
		}
		arr[size * (size - 1) + col] = element;
		col++;
	}
}

//row set as 0 bt default
int	solve(char *arr, char *argv, int size, int row)
{
	char	*str_row;

	init_first_permutation(arr, row, size);
	str_row = ft_str_row(row, arr, size);
	while (1)
	{
		if (check_left_right(str_row, size, argv, row) && check_element(arr, size, row))
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

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

void	ft_print(char *array, int size)
{
	int	i;

	i = 0;
	while (i < size * size)
	{
		write(1, &array[i], 1);
		if (i % size != size - 1)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*arr;
	int		size;
	int		i;

	if (argc == 2)
	{
		size = ft_size(argv[1]);
		if (size)
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
