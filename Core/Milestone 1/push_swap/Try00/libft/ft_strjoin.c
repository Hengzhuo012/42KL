/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:20:09 by zheng             #+#    #+#             */
/*   Updated: 2026/07/30 23:29:41 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i - len_s1 < len_s2)
	{
		str[i] = s2[i - len_s1];
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s1;
	char	*s2;
	char	*str;

	s1 = "Hello";
	s2 = "World";
	str = ft_strjoin(s1, s2);
	printf("%s", str);
	free(str);
}
*/
