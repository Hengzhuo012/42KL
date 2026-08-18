/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:36:27 by zheng             #+#    #+#             */
/*   Updated: 2026/07/30 16:24:15 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;

	a = 'b';
	b = 'B';
	printf("%c to upper is %c\n", a, ft_toupper(a));
	printf("%c to upper is %c\n", b, ft_toupper(b));
}
*/
