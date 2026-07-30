/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:01:59 by zheng             #+#    #+#             */
/*   Updated: 2026/07/28 14:18:48 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char const *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len_s;
	unsigned int	i;
	char			*arr;

	len_s = ft_strlen(s);
	arr = malloc((len_s + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	return (arr);
}

/*
#include <stdio.h>

char	test(unsigned int n, char c)
{
	return (c + (n % 2));
}

int	main(void)
{
	char	*arr;

	arr = ft_strmapi("Hello", &test);
	if (!arr)
	{
		printf("Allocation fails");
		return (1);
	}
	printf("%s\n", arr);
	free(arr);
	return (0);
}
*/
