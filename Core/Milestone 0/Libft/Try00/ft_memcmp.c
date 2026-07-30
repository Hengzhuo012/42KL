/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 09:16:15 by zheng             #+#    #+#             */
/*   Updated: 2026/07/30 16:43:55 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	unsigned int	i;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (c1[i] && c2[i] && c1[i] == c2[i] && i < n)
		i++;
	return (c1[i] - c2[i]);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	*s1;
	char	*s2;
	size_t	n;

	s1 = "Test1haha";
	s2 = "Test2haha";
	n = 5;
	printf("Real: %d\n", memcmp(s1, s2, n));
	printf("Mine: %d\n", ft_memcmp(s1, s2, n));
}
*/
