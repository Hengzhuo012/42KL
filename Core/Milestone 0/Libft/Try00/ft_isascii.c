/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:26:06 by zheng             #+#    #+#             */
/*   Updated: 2026/07/27 10:37:56 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;

	a = 'h';
	b = 130;

	printf("%d, is %d\n", a, ft_isascii(a));
	printf("%d, is %d\n", b, ft_isascii(b));
}
*/
