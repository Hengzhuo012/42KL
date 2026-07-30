/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 09:43:56 by zheng             #+#    #+#             */
/*   Updated: 2026/07/28 10:06:22 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	long long		result;
	int				sign;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

/*
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	char	*str;

	str = "   \n\t  21474836471 ";
	printf("Real: %d\n", atoi(str));
	printf("Mine: %d\n", ft_atoi(str));
}
*/
