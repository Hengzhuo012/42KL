/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:45:34 by zheng             #+#    #+#             */
/*   Updated: 2026/07/30 22:57:01 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	const char		*str;
	unsigned int	start;
	size_t			len;
	char			*substr;

	str = "Hello World";
	start = 6;
	len = 6;
	substr = ft_substr(str, start, len);
	printf("%s", substr);
	free(substr);
}
*/