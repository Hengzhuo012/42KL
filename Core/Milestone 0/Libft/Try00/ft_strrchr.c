/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:57:11 by zheng             #+#    #+#             */
/*   Updated: 2026/07/27 15:00:11 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	i++;
	while (i || s[i] == (char)c)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	*str;
	int			c;

	str = "Hello";
	c = 'l';
	printf("REAL: %s\n", strrchr(str, c));
	printf("MINE: %s\n", ft_strrchr(str, c));
}
*/
