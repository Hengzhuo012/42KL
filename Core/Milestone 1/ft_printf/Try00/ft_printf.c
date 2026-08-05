/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:27:16 by zheng             #+#    #+#             */
/*   Updated: 2026/08/05 22:02:31 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_conversion(char c)
{
	char	*str;
	int		i;

	str = "cspdiuxX";
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	update_index(const char *s, int *i)
{
	while (!is_conversion(s[*i]) && s[*i])
		(*i)++;
	if (is_conversion(s[*i]) && s[*i])
		(*i)++;
}

static int	determine_and_proceed(const char *s, va_list *args)
{
	int	i;

	i = 0;
	while (s[i] && !is_conversion(s[i]))
		i++;
	if (s[i] == 'c')
		return (print_char(va_arg(*args, int)));
	if (s[i] == 's')
		return (print_string(va_arg(*args, char *)));
	if (s[i] == 'p')
		return (print_hexa_pointer(va_arg(*args, void *)));
	if (s[i] == 'd' || s[i] == 'i')
		return (print_decimal(va_arg(*args, int)));
	if (s[i] == 'u')
		return (print_unsigned_decimal(va_arg(*args, unsigned int)));
	if (s[i] == 'x' || s[i] == 'X')
		return (print_hexa_number(va_arg(*args, unsigned int), (s[i] == 'X')));
	return (0);
}

static void	check_conversion_and_proceed(const char *s, int *i,
int *count_output, va_list *args)
{
	if (s[*i + 1] == '%')
	{
		ft_putchar_fd('%', 1);
		(*i) += 2;
		(*count_output)++;
	}
	else
	{
		(*count_output) += determine_and_proceed(&s[*i + 1], args);
		update_index(s, i);
	}
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count_output;
	va_list	args;

	va_start(args, s);
	i = 0;
	count_output = 0;
	while (s[i])
	{
		if (s[i] == '%')
			check_conversion_and_proceed(s, &i, &count_output, &args);
		else
		{
			ft_putchar_fd(s[i], 1);
			i++;
			count_output++;
		}
	}
	va_end(args);
	return (count_output);
}
