/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversions_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:56:46 by zheng             #+#    #+#             */
/*   Updated: 2026/08/05 21:59:23 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_unsigned_decimal_in_hexa(unsigned int n, int hexa_num_len,
int is_upper)
{
	char		buffer[16];
	char		*hexa;
	int			i;

	if (is_upper)
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	i = hexa_num_len - 1;
	while (i >= 0)
	{
		buffer[i] = hexa[n % 16];
		n /= 16;
		i--;
	}
	i = 0;
	while (i < hexa_num_len)
		ft_putchar_fd(buffer[i++], 1);
}

int	print_hexa_number(unsigned int n, int is_upper)
{
	int				hexa_num_len;
	unsigned int	temp;

	hexa_num_len = 1;
	temp = n;
	while (temp >= 16)
	{
		hexa_num_len++;
		temp /= 16;
	}
	print_unsigned_decimal_in_hexa(n, hexa_num_len, is_upper);
	return (hexa_num_len);
}
