/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:01:06 by zheng             #+#    #+#             */
/*   Updated: 2026/08/02 22:59:57 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//const char *s got the letter right after %
//char c got the first arg
//only cares about number (right align) and '-'

static void	get_width(const char *s, int *i, int *len)
{
	while (s[*i] && ft_isdigit(s[*i]))
	{
		*len = (*len * 10) + (s[*i] - '0');
		(*i)++;
	}
}
static void skip_precision(const char *s, int *i)
{
	(*i)++;
	while (s[*i] && ft_isdigit(s[*i]))
		(*i)++;
}
static void	check_flags_char(const char *s, int *mode, int *len)
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
			get_width(s, &i, len);
		}
		else
			i++;
	}
}

static void	print_padding(int len)
{
	int	i;
	
	i = 0;
	while (i < len - 1)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}

int	print_char(const char *s, char c)
{
	int	len;
	int	mode;

	len = 0;
	mode = 0;
	check_flags_char(s, &mode, &len);
	if (mode == 1)
		ft_putchar_fd(c, 1);
	if (mode != 0)
		print_padding(len);
	if (mode == 2 || mode == 0)
		ft_putchar_fd(c, 1);
	if (len == 0)
		return (1);
	return (len);
}

// int	main(void)
// {
// 	print_char("-5c", 'c');
// }