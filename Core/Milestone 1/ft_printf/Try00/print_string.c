/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:11:32 by zheng             #+#    #+#             */
/*   Updated: 2026/08/03 23:16:05 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_flags_string(const char *s, int *mode,
int *width, int *precision)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != 's')
	{
		if (s[i] == '.')
			(*precision) = get_precision(s, &i);
		else if (s[i] == '-')
		{
			*mode = 1;
			i++;
		}
		else if (ft_isdigit(s[i]))
		{
			if (*mode != 1)
				*mode = 2;
			get_width_and_update_index(s, &i, width);
		}
		else
			i++;
	}
}

static void	ft_putstrn_fd(char *s, int fd, int n)
{
	int	i;

	i = 0;
	while (s[i] && i < n)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int	print_string(const char *s, char *str)
{
	int	width;
	int	mode;
	int	precision;
	int	str_len;

	if (!str)
		str = "(null)";
	width = 0;
	mode = 0;
	str_len = ft_strlen(str);
	precision = str_len;
	check_flags_string(s, &mode, &width, &precision);
	if (precision > str_len)
		precision = str_len;
	if (mode == 1)
		ft_putstrn_fd(str, 1, precision);
	if (mode != 0 && width > precision)
		print_padding(' ', width - precision);
	if (mode == 2 || mode == 0)
		ft_putstrn_fd(str, 1, precision);
	if (width > precision)
		return (width);
	return (precision);
}

/*
ccc print_string.c print_helper.c ./libft/ft_isdigit.c
./libft/ft_putchar_fd.c ./libft/ft_strlen.c
*/
// #include <stdio.h>
// int	main(void)
// {
// 	write(1, "Without flags:", ft_strlen("Without flags:"));
// 	print_string("%s", "Hello");
// 	write(1, "\n", 1);

// 	print_string("%8s", "Hello");
// 	write(1, "\n", 1);
// 	print_string("%3s", "Hello");
// 	write(1, "\n", 1);
// 	print_string("%-8s", "Hello");
// 	write(1, "\n", 1);
// 	print_string("%-3s", "Hello");
// 	write(1, "\n", 1);

// 	print_string("%8.5s", "Hello");
// 	write(1, "\n", 1);
// 	print_string("%3.5s", "Hello");
// 	write(1, "\n", 1);
// 	print_string("%-8.5s", "Hello");
// 	write(1, "\n", 1);
// 	print_string("%-3.5s", "Hello");
// 	write(1, "\n", 1);

// 	print_string("%8.2s", "Hello");
// 	write(1, "\n", 1);
// 	print_string("%3.2s", "Hello");
// 	write(1, "\n", 1);
// 	print_string("%-8.2s", "Hello");
// 	write(1, "\n", 1);
// 	print_string("%-3.2s", "Hello");
// 	write(1, "\n", 1);
// }
