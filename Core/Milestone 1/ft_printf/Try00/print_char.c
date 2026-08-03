/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:01:06 by zheng             #+#    #+#             */
/*   Updated: 2026/08/03 23:16:16 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//const char *s got the letter right after %
//char c got the first arg
//only cares about number (right align) and '-'

static void	check_flags_char(const char *s, int *mode, int *width)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != 'c')
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
			if (*mode != 1)
				*mode = 2;
			get_width_and_update_index(s, &i, width);
		}
		else
			i++;
	}
}

int	print_char(const char *s, char c)
{
	int	width;
	int	mode;

	width = 0;
	mode = 0;
	check_flags_char(s, &mode, &width);
	if (mode == 1)
		ft_putchar_fd(c, 1);
	if (mode != 0)
		print_padding(' ', width - 1);
	if (mode == 2 || mode == 0)
		ft_putchar_fd(c, 1);
	if (width == 0)
		return (1);
	return (width);
}

// int	main(void)
// {
// 	print_char("-5c", 'c');
// }