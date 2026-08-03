/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:12:40 by zheng             #+#    #+#             */
/*   Updated: 2026/08/03 21:01:00 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
(mode 0)
%p -> output 0x followed by hex address in lowercase

(mode 2)
%(width)p -> padding with ending ' ', right-aligned
				only if width > length else ignore

(mode 1)
%-(width)p -> padding with leading ' ', left-aligned
				only if width > length else ignore

(mode 3)
%0(width)p -> padding with leading '0' after '0x', right-aligned
				only if width > length else ignore
				eg: 0x0000005c3bf190907a
OR
-> same to mode 2
*/

#include "ft_printf.h"

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

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return ;
	}
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

static void	check_flags_hexa_pointer(const char *s, int *mode, int *len)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != 'p')
	{
		if (s[i] == '.')
			skip_precision(s, &i);
		else if (s[i] == '-')
		{
			*mode = 1;
			i++;
		}
		else if (ft_isdigit(s[i]))
		{
			if (*mode != 1 && s[i] != '0')
				*mode = 2;
			else if (*mode != 1)
				*mode = 3;
			get_width_and_update_index(s, &i, len);
		}
		else
			i++;
	}
}

static	void print_hexa_pointer_mode(void *ptr, int mode, int len, int total_len)
{
	int	len_hexa_ptr;

	len_hexa_ptr = count_hexa_length(ptr);
	if (mode == 1)
	{
		print_decimal_in_hexa(ptr, len_hexa_ptr);
		if (len > total_len)
			print_padding(' ', len - total_len);
	}
	else if (mode == 2 || mode == 3)
	{
		if (len > total_len)
			print_padding(' ', len - total_len);
		print_decimal_in_hexa(ptr, len_hexa_ptr);
	}
	else
		print_decimal_in_hexa(ptr, len_hexa_ptr);
}

// if 0x00000asoi4214sda is required, 
// static void	print_hexa_pointer_mode(void *ptr, int mode, int len, int total_len)
// {
// 	int	len_hexa_ptr;
//
// 	len_hexa_ptr = count_hexa_length(ptr);
// 	/* mode 1: Left-aligned with spaces */
// 	if (mode == 1)
// 	{
// 		print_decimal_in_hexa(ptr, len_hexa_ptr);
// 		if (len > total_len)
// 			print_padding(' ', len - total_len);
// 	}
// 	/* mode 2: Right-aligned with spaces */
// 	else if (mode == 2)
// 	{
// 		if (len > total_len)
// 			print_padding(' ', len - total_len);
// 		print_decimal_in_hexa(ptr, len_hexa_ptr);
// 	}
// 	/* mode 3: Zero-padded (%020p -> 0x0000005d...) */
// 	else if (mode == 3)
// 	{
// 		if (!ptr)
// 		{
// 			if (len > total_len)
// 				print_padding(' ', len - total_len);
// 			ft_putstr_fd("(nil)", 1);
// 			return ;
// 		}
// 		ft_putstr_fd("0x", 1);
// 		if (len > total_len)
// 			print_padding('0', len - total_len);
// 		print_hex_digits_only(ptr, len_hexa_ptr);
// 	}
// 	else
// 		print_decimal_in_hexa(ptr, len_hexa_ptr);
// }


int	print_hexa_pointer(const char *s, void *ptr)
{
	int		len;
	int		mode;
	int		total_len;

	len = 0;
	mode = 0;
	check_flags_hexa_pointer(s, &mode, &len);
	if (!ptr)
		total_len = 5;
	else
		total_len = count_hexa_length(ptr) + 2;
	print_hexa_pointer_mode(ptr, mode, len, total_len);
	if (len > total_len)
		return (len);
	return (total_len);
}

#include <stdio.h>
int	main(void)
{
	int	i = 10;
	int	*ptr = &i;

	write(1, "Without flags:", ft_strlen("Without flags:"));
	print_hexa_pointer("p", ptr);
	ft_putchar_fd('\n', 1);

	print_hexa_pointer("20p", ptr);
	ft_putchar_fd('\n', 1);
	print_hexa_pointer("-20p", ptr);
	ft_putchar_fd('\n', 1);
	print_hexa_pointer("020p", ptr);
	ft_putchar_fd('\n', 1);
}