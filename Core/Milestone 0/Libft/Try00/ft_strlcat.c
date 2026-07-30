/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:12:24 by zheng             #+#    #+#             */
/*   Updated: 2026/07/27 14:36:05 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dst_len >= size)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	char	src[] = "letters";
	char	dest_real[20] = "random";
	char	dest_mine[20] = "random";
	int		n = 10;
	printf("MINE\nsrc: %s\nLength returned: ", src);
	printf("%zu\n", ft_strlcat(dest_mine, src, n));
	printf("dest: %s\n", dest_mine);
	printf("REAL\nsrc: %s\nLength returned: ", src);
	printf("%zu\n", strlcat(dest_real, src, n));
	printf("dest: %s\n", dest_real);
}
*/
