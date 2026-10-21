/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:31:25 by zheng             #+#    #+#             */
/*   Updated: 2026/07/23 15:31:49 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_str_row(int row, char *arr, int size)
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
		arr[row + i] = '1' + i;
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
