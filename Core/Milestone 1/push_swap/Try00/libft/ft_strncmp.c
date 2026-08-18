/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:06:06 by zheng             #+#    #+#             */
/*   Updated: 2026/07/30 16:29:52 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	c1 = (unsigned char) s1[i];
	c2 = (unsigned char) s2[i];
	return (c1 - c2);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s1[] = "Test0";
	char	s2[] = "Test2";
	int		n = 5;

	printf("Mine: %d\n", ft_strncmp(s1, s2, n));
	printf("Real: %d\n", strncmp(s1, s2, n));
}
*/
