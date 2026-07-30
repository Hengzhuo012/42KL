/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:20:14 by zheng             #+#    #+#             */
/*   Updated: 2026/07/27 10:38:06 by zheng            ###   ########.fr       */
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

	a = ' ';
	b = '4';
	c = 'c';

	printf("%d, is %d\n", a, ft_isdigit(a));
	printf("%d, is %d\n", b, ft_isdigit(b));
	printf("%d, is %d\n", c, ft_isdigit(c));
}
*/
