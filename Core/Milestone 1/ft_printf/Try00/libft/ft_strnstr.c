/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 09:25:04 by zheng             #+#    #+#             */
/*   Updated: 2026/07/30 16:57:36 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[0])
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while ((i + j) < len && big[i + j] == little[j]
			&& big[i + j] && little[j])
		{
			j++;
			if (!little[j])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	const char	*big;
	const char	*little;
	size_t		n;

	big = "AABC";
	little = "ABC";
	n = 4;
	printf("Real: %s\n", strnstr(big, little, n));
	printf("Mine: %s\n", ft_strnstr(big, little, n));
}
*/
