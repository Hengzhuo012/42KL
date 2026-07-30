/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:41:32 by zheng             #+#    #+#             */
/*   Updated: 2026/07/27 12:29:43 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	str1[10];
	char	str2[10];

	ft_memset(str1, 'h', 5);
	str1[5] = '\0';
	memset(str2, 'h', 5);
	str2[5] = '\0';
	printf("str1 = %s\n", str1);
	printf("str2 = %s\n", str2);
}
*/
