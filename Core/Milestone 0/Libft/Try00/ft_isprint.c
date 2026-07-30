/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:32:09 by zheng             #+#    #+#             */
/*   Updated: 2026/07/30 15:53:54 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}

/*
#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;

	a = 'h';
	b = '\t';

	printf("%c, is %d\n", (char)a, ft_isprint(a));
	printf("%c, is %d\n", (char)b, ft_isprint(b));
}
*/
