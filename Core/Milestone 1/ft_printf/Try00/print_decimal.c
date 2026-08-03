/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 22:14:30 by zheng             #+#    #+#             */
/*   Updated: 2026/08/03 23:30:43 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
(mode 0)
%d

(mode 1)
%-(width)d -> padding with leading ' ', left-aligned
				only if width > widthgth else ignore
				if %-5d, d = -42, output = "-42  "

(mode 2)
%(width)d -> padding with ending ' ', right-aligned
				only if width > widthgth else ignore
				if %5d, d = -42, output = "  -42"

(mode 3)
%0(width)d -> padding with leading '0', right-aligned
				only if width > widthgth else ignore
				if %05d, d = -42, output = "-0042"

(precision)
%.(precision)d -> min number of digits to output
					%.5d, d = -42, output = "-00042"
					%.0d, ignore precision
					%.0d, d = 0, output = (empty)
					ignore 0 flag

(prefix 1)
%+d -> print '+' prefix if number not negative
		overwrite ' ' flag

(prefix 2)
% d -> print ' ' prefix if number not negative
*/
#include "ft_printf.h"

static int digits_count(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void determine_prefix_flags_and_update_index(const char *s,
int *i, int *prefix)
{
	if (s[i] == '+')
		*prefix = 1;
	else if (s[i] == '-' && (*prefix) != 1)
		*prefix = 1;
	(*i)++;
		
}

static int	check_flags_decimal_and_return_width(const char *s,
int *mode, int *prefix, int *precision)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (s[i] && s[i] != 'd' && s[i] != 'i')
	{
		if (s[i] == '.')
			(*precision) = get_precision(s, &i);
		else if (s[i] == '-')
			*mode = 1;
		else if (ft_isdigit(s[i]))
		{
			if (*mode != 1 && s[i] != '0')
				*mode = 2;
			else if (*mode != 1)
				*mode = 3;
			get_width_and_update_index(s, &i, &width);
		}
		else if (s[i] == '+' || s[i] == ' ')
			determine_prefix_and_update_index(s, &i, prefix);
		else
			i++;
	}
	return (width);
}

int	print_decimal(const char *s, int n)
{
	int	width;
	int	mode;
	int	precision;
	int	len_n;
	int	prefix;

	mode = 0;
	prefix = 0;
	len_n = digits_count(n);
	precision = digits_count(n);
	width = check_flags_decimal(s, &mode, &precision);



	if (width > precision)
		return (width);
	return (precision);
}