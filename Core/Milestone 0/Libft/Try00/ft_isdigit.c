/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:16:54 by zheng             #+#    #+#             */
/*   Updated: 2026/07/27 10:19:51 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;

	a = 4;
	b = '4';

	printf("%d, is %d\n", a, ft_isdigit(a));
	printf("%d, is %d\n", b, ft_isdigit(b));
}
*/
