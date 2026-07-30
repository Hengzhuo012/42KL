/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 09:56:34 by zheng             #+#    #+#             */
/*   Updated: 2026/07/30 23:43:45 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_arr_size(char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			words++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (words);
}

void	ft_add_word(char *str, char *arr, int start, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = str[start + i];
		i++;
	}
	arr[i] = '\0';
}

char	**ft_free_all(char **arr, int count)
{
	while (count > 0)
	{
		count--;
		free(arr[count]);
	}
	free(arr);
	return (NULL);
}

char	**ft_create_array(char *str, char c, char **arr)
{
	int	i;
	int	start;
	int	arr_counter;

	i = 0;
	arr_counter = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			start = i;
			while (str[i] && str[i] != c)
				i++;
			arr[arr_counter] = malloc((i - start + 1) * sizeof(char));
			if (!arr[arr_counter])
				return (ft_free_all(arr, arr_counter));
			ft_add_word(str, arr[arr_counter], start, i);
			arr_counter++;
		}
	}
	arr[arr_counter] = NULL;
	return (arr);
}

char	**ft_split(char *str, char c)
{
	char	**arr;

	if (!str)
		return (NULL);
	arr = malloc((ft_arr_size(str, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (ft_create_array(str, c, arr));
}
/*
#include <stdio.h>
int	main(void)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split("test:hello", ':');
	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
*/