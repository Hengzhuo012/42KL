/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:19:01 by zheng             #+#    #+#             */
/*   Updated: 2026/07/28 14:29:47 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>

void	test(unsigned int n, char *c)
{
	(void)n;
	c[0] = c[0] + 1;
}

int	main(void)
{
	char	str[] = "Hello";

	printf("Before: %s\n", str);
	ft_striteri(str, &test);
	printf("After: %s\n", str);
	return (0);
}
*/
