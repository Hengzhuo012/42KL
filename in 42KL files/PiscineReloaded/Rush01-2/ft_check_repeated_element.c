/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_repeated_element.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:36:18 by zheng             #+#    #+#             */
/*   Updated: 2026/07/23 15:36:35 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_element(char *array, int size, int row)
{
	int	col;
	int	i_row;

	col = 0;
	while (col < size)
	{
		i_row = row - size + col;
		while (i_row >= 0)
		{
			if (array[i_row] == array[row + col])
				return (0);
			i_row -= size;
		}
		col++;
	}
	return (1);
}
