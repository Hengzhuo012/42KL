/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:32:09 by zheng             #+#    #+#             */
/*   Updated: 2026/07/27 10:37:25 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
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
	b = '\n';

	printf("%d, is %d\n", a, ft_isprint(a));
	printf("%d, is %d\n", b, ft_isprint(b));
}
*/
