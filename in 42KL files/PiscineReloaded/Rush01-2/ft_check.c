/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 12:56:42 by zheng             #+#    #+#             */
/*   Updated: 2026/07/23 13:31:21 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_visible(char *str, char largest, int size, int dir)
{
	int	diff;
	int	i;
	int	index;

	diff = 1;
	i = 0;
	while (i < size)
	{
		if (dir == 1)
			index = i;
		else
			index = size - 1 - i;
		if (str[index] > largest)
		{
			largest = str[index];
			diff += 1;
		}
		i++;
	}
	return (diff);
}

/*
check if matches the input, if passes return 1 else 0
str is the value to be test like "1234"
front_input is where it counts from i = 0
size_of_array is 4 for base question, up to 9 for bonus

if row, front and back are left and right
if col, front and back are top and bottom
*/
int	ft_check(char *str, int front_input, int back_input, int size_array)
{
	char	largest_front;
	char	largest_back;
	int		diff_front;
	int		diff_back;

	largest_front = str[0];
	largest_back = str[size_array - 1];
	diff_front = ft_check_visible(str, largest_front, size_array, 1);
	diff_back = ft_check_visible(str, largest_back, size_array, -1);
	if (diff_front == (front_input - '0') && diff_back == (back_input - '0'))
		return (1);
	return (0);
}

//Check the row number with the inputs for that row
//Return 1 if passes, 0 if failed
int	check_left_right(char *str_row, int size, char *argv, int row)
{
	char	left_input;
	char	right_input;

	left_input = argv[(((row / size) * 2) + (4 * size))];
	right_input = argv[(((row / size) * 2) + (6 * size))];
	return (ft_check(str_row, left_input, right_input, size));
}

//Used for ft_diff_check_col
//Return 0 if failed, 1 if passes
int	check_one_top_bot(char *str, int size, int col, char *argv)
{
	char	top_input;
	char	bot_input;

	top_input = argv[col * 2];
	bot_input = argv[(col + size) * 2];
	return (ft_check(str, top_input, bot_input, size));
}

//Check if all inputs for col matches
//return 1 if passes, 0 if failed
int	check_top_bot(char *array, int size, char *argv)
{
	char	*str_col;
	int		col;
	int		i;

	str_col = malloc(size * sizeof(char));
	col = 0;
	while (col < size)
	{
		i = 0;
		while (i < size)
		{
			str_col[i] = array[(col % size) + (size * i)];
			i++;
		}
		if (check_one_top_bot(str_col, size, col, argv) == 0)
		{
			free(str_col);
			return (0);
		}
		col++;
	}
	free(str_col);
	return (1);
}
