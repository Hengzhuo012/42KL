/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 11:21:06 by zheng             #+#    #+#             */
/*   Updated: 2026/07/30 16:01:20 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

/*
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	char	str1[10] = "12345";
	char	str2[10] = "12345";

	ft_bzero(str1, 5);
	bzero(str2, 5);
	printf("Mine = %s\n", str1);
	printf("Real = %s\n", str2);
}
*/
