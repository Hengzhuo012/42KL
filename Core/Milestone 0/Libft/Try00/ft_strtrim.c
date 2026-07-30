/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:44:15 by zheng             #+#    #+#             */
/*   Updated: 2026/07/28 13:02:36 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_set_start(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (ft_isset(s1[start], set))
		start++;
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		size;
	int		i;
	char	*str;

	start = ft_set_start(s1, set);
	end = ft_strlen(s1) - 1;
	while (ft_isset(s1[end], set))
		end--;
	size = end - start + 1;
	if (size < 0)
		return (NULL);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*str;
	char	*set;
	char	*strtrim;

	str = "&&&#*##&Hello&***#&";
	set = "&#*";
	strtrim = ft_strtrim(str, set);
	printf("%s\n", strtrim);
	free(strtrim);
}
*/
