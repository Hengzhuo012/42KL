/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:37:36 by zheng             #+#    #+#             */
/*   Updated: 2026/07/27 12:57:56 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	dest1[10];
	char	*src1;
	char	dest2[10];
	char	*src2;

	src1 = "Hello";
	src2 = "Hello";
	ft_memcpy(dest1, src1, 3);
	dest1[3] = 0;
	memcpy(dest2, src2, 3);
	dest2[3] = 0;
	printf("dest1, %s\n", dest1);
	printf("dest2, %s\n", dest2);
}
*/
