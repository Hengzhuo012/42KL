/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:28:26 by zheng             #+#    #+#             */
/*   Updated: 2026/08/05 21:59:20 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_string(char *str)
{
	int	str_len;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (str_len);
}

static int	count_hexa_length(void *ptr)
{
	unsigned long long	nbr;
	int					len_hexa_ptr;

	if (!ptr)
		return (5);
	nbr = (unsigned long long)ptr;
	len_hexa_ptr = 1;
	while (nbr >= 16)
	{
		len_hexa_ptr++;
		nbr /= 16;
	}
	return (len_hexa_ptr);
}

static void	print_decimal_in_hexa(void *ptr, int len_hexa_ptr)
{
	unsigned long long	nbr;
	char				buffer[16];
	char				*hexa;
	int					i;

	ft_putstr_fd("0x", 1);
	nbr = (unsigned long long)ptr;
	hexa = "0123456789abcdef";
	i = len_hexa_ptr - 1;
	while (i >= 0)
	{
		buffer[i] = hexa[nbr % 16];
		nbr /= 16;
		i--;
	}
	i = 0;
	while (i < len_hexa_ptr)
		ft_putchar_fd(buffer[i++], 1);
}

int	print_hexa_pointer(void *ptr)
{
	int					len_hexa_ptr;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len_hexa_ptr = count_hexa_length(ptr);
	print_decimal_in_hexa(ptr, len_hexa_ptr);
	return (len_hexa_ptr + 2);
}
