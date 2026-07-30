/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:34:21 by zheng             #+#    #+#             */
/*   Updated: 2026/07/28 10:44:41 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = 0;
	while (s[len])
		len++;
	str = malloc ((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*src;
	char	*new_str;

	src = "test\0";
	printf("Source: %s\n", src);
	new_str = ft_strdup(src);
	printf("New: %s\n", new_str);
	free(new_str);
}
*/
