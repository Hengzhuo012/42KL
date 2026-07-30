/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:09:16 by zheng             #+#    #+#             */
/*   Updated: 2026/07/30 15:47:26 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/*
#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;

	a = '-';
	b = 'c';
	printf("%c, is %d\n", (char)a, ft_isalpha(a));
	printf("%c, is %d\n", (char)b, ft_isalpha(b));
}
*/
