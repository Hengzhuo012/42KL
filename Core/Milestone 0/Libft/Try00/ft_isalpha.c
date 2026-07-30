/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:09:16 by zheng             #+#    #+#             */
/*   Updated: 2026/07/27 10:16:41 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;

	a = ' ';
	b = 'c';
	printf("%d, is %d\n", a, ft_isalpha(a));
	printf("%d, is %d\n", b, ft_isalpha(b));
}
*/
