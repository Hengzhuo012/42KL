/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:29:32 by zheng             #+#    #+#             */
/*   Updated: 2026/07/28 14:01:30 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*int_min(void)
{
	char	*arr;

	arr = malloc(12 * sizeof(char));
	if (!arr)
		return (NULL);
	arr[0] = '-';
	arr[1] = '2';
	arr[2] = '1';
	arr[3] = '4';
	arr[4] = '7';
	arr[5] = '4';
	arr[6] = '8';
	arr[7] = '3';
	arr[8] = '6';
	arr[9] = '4';
	arr[10] = '8';
	arr[11] = '\0';
	return (arr);
}

int	ft_nbsize(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*arr;
	char	c;
	int		is_negative;
	int		size;

	if (n == -2147483648)
		return (int_min());
	is_negative = (n < 0);
	if (n < 0)
		n *= -1;
	size = ft_nbsize(n);
	arr = malloc((size + is_negative + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	if (is_negative)
		arr[0] = '-';
	arr[size + is_negative] = 0;
	while (size > 0)
	{
		c = (n % 10) + '0';
		arr[size - 1 + is_negative] = c;
		n /= 10;
		size--;
	}
	return (arr);
}

/*
#include <stdio.h>
int	main(void)
{
	int		n1;
	int		n2;
	int		n3;
	int		n4;
	int		n5;
	char	*arr;

	n1 = -2147483648;
	arr = ft_itoa(n1);
	printf("%d: %s\n", n1, arr);
	free(arr);
	n2 = 2147483647;
	arr = ft_itoa(n2);
	printf("%d: %s\n", n2, arr);
	free(arr);
	n3 = 0;
	arr = ft_itoa(n3);
	printf("%d: %s\n", n3, arr);
	free(arr);
	n4 = 217;
	arr = ft_itoa(n4);
	printf("%d: %s\n", n4, arr);
	free(arr);
	n5 = -217;
	arr = ft_itoa(n5);
	printf("%d: %s\n", n5, arr);
	free(arr);
}
*/
