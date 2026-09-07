/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:16:54 by zheng             #+#    #+#             */
/*   Updated: 2026/07/30 15:47:32 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int n)
{
	return (n >= '0' && n <= '9');
}

/*
#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;

	a = 'c';
	b = '4';

	printf("%c, is %d\n", (char)a, ft_isdigit(a));
	printf("%c, is %d\n", (char)b, ft_isdigit(b));
}
*/
