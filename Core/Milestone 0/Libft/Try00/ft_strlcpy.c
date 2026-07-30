/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 13:48:55 by zheng             #+#    #+#             */
/*   Updated: 2026/07/30 16:03:01 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	len = 0;
	while (src[len])
		len++;
	return (len);
}

/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	*src;
	char	dest_real[20] = {0};
	char	dest_mine[20] = {0};

	src = "Testing";
	strlcpy(dest_real, src, 5);
	ft_strlcpy(dest_mine, src, 5);
	printf("Real: %s\n", dest_real);
	printf("Mine: %s\n", dest_mine);
}
*/
