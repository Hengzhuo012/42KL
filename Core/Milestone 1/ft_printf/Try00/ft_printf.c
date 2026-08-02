/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:22:46 by zheng             #+#    #+#             */
/*   Updated: 2026/08/02 01:35:21 by zheng            ###   ########.fr       */
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

-----------PART 2-----------
%#x -> prefix with '0x'
%#X -> prefix with '0X'
%+d -> output '+' prefix if not negative

*/

/*
IDEA
check for flags, if -0. get number. check until cspdiux
then based on which conversion, va_arg which data type
then pass to which function
*/

#include "ft_printf.h"

static int	is_conversion_percentage(char c, int *i, int *count_output)
{
	if (c == '%')
	{
		ft_putchar('%');
		i++;
		count_output++;
		return (1);
	}
	return (0);
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
		{
			if (!is_conversion_percentage(s[i + 1], &i, &count_output))
				count_output += check_and_proceed(s[i + 1], &args, &i);
		}
		else
		{
			ft_putchar(s[i++]);
			count_output++;
		}
	}
	va_end(args);
	return (count_output);
}
