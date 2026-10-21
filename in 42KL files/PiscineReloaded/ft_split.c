/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:10:43 by zheng             #+#    #+#             */
/*   Updated: 2026/07/24 13:23:31 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	word_count(char *str)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (is_sep(str[i]) && str[i])
			i++;
		if (!is_sep(str[i]) && str[i])
		{
			word++;
			while (!is_sep(str[i]) && str[i])
				i++;
		}
	}
	return (word);
}

char	*ft_add_word(char *str, char *arr, int start, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = str[start + i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_create_arr(char *str, char **arr)
{
	int	i;
	int	start;
	int	arr_counter;
	int	size;

	i = 0;
	arr_counter = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i]))
			i++;
		if (str[i])
		{
			start = i;
			while (str[i] && !is_sep(str[i]))
				i++;
			size = i - start;
			arr[arr_counter] = malloc((size + 1) * sizeof(char));
			arr[arr_counter] = ft_add_word(str, arr[arr_counter], start, size);
			arr_counter++;
		}
	}
	arr[arr_counter] = NULL;
	return (arr);
}

char	**ft_split(char *str)
{
	char	**arr;

	arr = malloc((word_count(str) + 1) * sizeof(char *));
	if (!str[0])
	{
		arr[0] = NULL;
		return (arr);
	}
	arr = ft_create_arr(str, arr);
	return (arr);
}

/*
#include <stdio.h>
int	main(void)
{
	char	**arr;
	int	i;

	i = 0;
	arr = ft_split("test hello");
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
