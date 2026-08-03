/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 13:52:30 by zheng             #+#    #+#             */
/*   Updated: 2026/08/03 20:07:05 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	skip_precision(const char *s, int *i)
{
	(*i)++;
	while (s[*i] && ft_isdigit(s[*i]))
		(*i)++;
}

void	get_width_and_update_index(const char *s, int *i, int *len)
{
	while (s[*i] && ft_isdigit(s[*i]))
	{
		*len = (*len * 10) + (s[*i] - '0');
		(*i)++;
	}
}

void	print_padding(char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
}
