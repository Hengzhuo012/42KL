/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:42:38 by zheng             #+#    #+#             */
/*   Updated: 2026/07/27 14:43:38 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
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
	printf("%c to lower is %c\n", a, ft_tolower(a));
	printf("%c to lower is %c\n", b, ft_tolower(b));
}
*/
