/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:06:29 by zheng             #+#    #+#             */
/*   Updated: 2026/07/28 10:34:09 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			i;
	unsigned char	*cptr;

	if (nmemb != 0 && size > (size_t)-1 / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	cptr = (unsigned char *)ptr;
	while (i < (nmemb * size))
		cptr[i++] = 0;
	return (ptr);
}

/*
#include <stdio.h>
int	main(void)
{
	size_t	count = 5;
	size_t	bytes = sizeof(int);
	int		*arr;
	size_t	i;

	arr = (int *)ft_calloc(count, bytes);
	if (arr == NULL)
	{
		printf("Allocation failed\n");
		return (1);
	}
	i = 0;
	while (i < count)
	{
		printf("arr[%zu] = %d\n", i, arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
*/
