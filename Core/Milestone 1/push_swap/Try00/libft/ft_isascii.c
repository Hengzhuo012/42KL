/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:26:06 by zheng             #+#    #+#             */
/*   Updated: 2026/07/30 15:54:03 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*
#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;

	a = 'h';
	b = 130;

	printf("%c, is %d\n", (char)a, ft_isascii(a));
	printf("%c, is %d\n", (char)b, ft_isascii(b));
}
*/
