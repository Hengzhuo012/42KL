/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:01:59 by zheng             #+#    #+#             */
/*   Updated: 2026/07/31 10:17:56 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len_s;
	unsigned int	i;
	char			*arr;

	if (!s || !f)
		return (NULL);
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
	arr[i] = '\0';
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
