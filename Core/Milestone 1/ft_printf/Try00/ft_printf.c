/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:22:46 by zheng             #+#    #+#             */
/*   Updated: 2026/08/05 13:56:36 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//flags meaning
/*
-----------PART 1-----------
int d = 4;
%-5d -> min have 5 chars inc digits (output = "4    ")
%05d -> min have 5 chars inc digits with prefix '0' (output = "00004")

'-' overwrite '0'

%.5d -> min have 5 chars inc digits (output = "00004")
if d = 123456, (output = "123456")
%.5u -> same
%.5x / %.5X -> same but output nothing if value is 0
%.5s -> print MAX 5 chars, if less than 5, no need add chars
others ignore it

must use flags first before using '.'
'.' overwrite '0' on 'diuxX' (technically they are the same)
'.' works tgt with '-' on 'diuxX' %-7.5d(output "00005  ")

if no number behind '-' or '0', it acts like it is '-0' or '00'
%.d same as %.0d
%.0d, d=42 prints '42'
%.0d, d = 0 prints nothing
%.0s 100% prints nothing

-----------PART 2-----------
%#x -> prefix with '0x'
%#X -> prefix with '0X'
BOTH below only applied on SIGNED Numbers
%+d -> output '+' prefix if not negative
% d -> output ' ' prefix if not negative

*/

/*
IDEA
check for flags, if -0. get number. check until cspdiux
then based on which conversion, va_arg which data type
then pass to which function
*/

#include "ft_printf.h"

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
		return (print_char(s, va_arg(*args, int)));
	if (s[i] == 's')
		return (print_string(s, va_arg(*args, char *)));
	if (s[i] == 'p')
		return (print_hexa_pointer(s, va_arg(*args, void *)));
	if (s[i] == 'd' || s[i] == 'i')
		return (print_decimal(s, va_arg(*args, int)));
	if (s[i] == 'u')
		return (print_unsigned_decimal(s, va_arg(*args, unsigned int)));
	if (s[i] == 'x' || s[i] == 'X')
		return (print_hexa_number(s,
				va_arg(*args, unsigned int), (s[i] == 'X')));
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
