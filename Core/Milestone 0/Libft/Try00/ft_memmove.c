/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:57:01 by zheng             #+#    #+#             */
/*   Updated: 2026/07/27 13:48:44 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (n > 0)
		{
			*d = *s;
			d++;
			s++;
			n--;
		}
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src1[20] = "Hello World";
	char	dest_real[20] = {0};
	char	dest_mine[20] = {0};

	memmove(dest_real, src1, 11);
	ft_memmove(dest_mine, src1, 11);
	printf("Real: %s\n", dest_real);
	printf("Mine: %s\n", dest_mine);
	
	char	test_real[20] = "0123456789";
	char	test_mine[20] = "0123456789";

	memmove(test_real + 2, test_real, 5);
	ft_memmove(test_mine + 2, test_mine, 5);
	printf("Real: %s\n", test_real);
	printf("Mine: %s\n", test_mine);

	char	test_real2[20] = "0123456789";
	char	test_mine2[20] = "0123456789";

	memmove(test_real2, test_real2 + 2, 5);
	ft_memmove(test_mine2, test_mine2 + 2, 5);
	printf("Real: %s\n", test_real2);
	printf("Mine: %s\n", test_mine2);
}
*/
