/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:11:32 by zheng             #+#    #+#             */
/*   Updated: 2026/08/03 16:04:37 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_precision(const char *s, int *i)
{
	int	precision;

	precision = 0;
	(*i)++;
	while (s[*i] && ft_isdigit(s[*i]))
	{
		precision = (precision * 10) + (s[*i] - '0');
		(*i)++;
	}
	return (precision);
}

static void	check_flags_string(const char *s, int *mode,
int *len, int *precision)
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
			get_width_and_update_index(s, &i, len);
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
	int	len;
	int	mode;
	int	precision;
	int	str_len;

	if (!str)
		str = "(null)";
	len = 0;
	mode = 0;
	str_len = ft_strlen(str);
	precision = str_len;
	check_flags_string(s, &mode, &len, &precision);
	if (precision > str_len)
		precision = str_len;
	if (mode == 1)
		ft_putstrn_fd(str, 1, precision);
	if (mode != 0 && len > precision)
		print_padding(' ', len - precision);
	if (mode == 2 || mode == 0)
		ft_putstrn_fd(str, 1, precision);
	if (len > precision)
		return (len);
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
