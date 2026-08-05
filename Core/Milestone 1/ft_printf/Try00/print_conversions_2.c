/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:42:52 by zheng             #+#    #+#             */
/*   Updated: 2026/08/05 21:56:54 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_unsignednbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n > 9)
	{
		put_unsignednbr_fd(n / 10, fd);
		put_unsignednbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

static int	digits_count(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	print_decimal(int n)
{
	int				digit_len;
	int				print_len;
	unsigned int	num;

	print_len = 0;
	if (n < 0)
	{
		num = (unsigned int)(-(long)n);
		ft_putchar_fd('-', 1);
		print_len = 1;
	}
	else
		num = (unsigned int)n;
	digit_len = digits_count(num);
	print_len += digit_len;
	put_unsignednbr_fd(num, 1);
	return (print_len);
}

int	print_unsigned_decimal(unsigned int n)
{
	int				digit_len;

	digit_len = digits_count(n);
	put_unsignednbr_fd(n, 1);
	return (digit_len);
}
