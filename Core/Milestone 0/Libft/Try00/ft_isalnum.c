/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:20:14 by zheng             #+#    #+#             */
/*   Updated: 2026/07/30 15:48:55 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;
	int	c;

	a = '-';
	b = '4';
	c = 'c';

	printf("%c, is %d\n", (char)a, ft_isalnum(a));
	printf("%c, is %d\n", (char)b, ft_isalnum(b));
	printf("%c, is %d\n", (char)c, ft_isalnum(c));
}
*/
