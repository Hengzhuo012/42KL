/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 23:20:21 by zheng             #+#    #+#             */
/*   Updated: 2026/08/05 02:05:17 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
(mode 0)
%u

(mode 1)
%-(width)u -> padding with leading ' ', left-aligned
				only if width > widthgth else ignore
				overwrite 0 flag

(mode 2)
%(width)u -> padding with ending ' ', right-aligned
				only if width > widthgth else ignore

(mode 3)
%0(width)u -> padding with leading '0', right-aligned
				only if width > widthgth else ignore

(precision)
%.(precision)u -> min number of digits to output
					ignore flag 0 if exsists
					%.0u, u = 0, output = (empty)
*/

#include "ft_printf.h"

static void	check_flags_unsigned_decimal(const char *s, t_vars *vars)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != 'u')
	{
		if (s[i] == '.')
			vars->precision = get_precision(s, &i);
		else if (s[i] == '-')
		{
			vars->mode = 1;
			i++;
		}
		else if (ft_isdigit(s[i]))
		{
			if (vars->mode == 0 && s[i] == '0')
				vars->mode = 3;
			else if (vars->mode == 0)
				vars->mode = 2;
			get_width_and_update_index(s, &i, &vars->width);
		}
		else
			i++;
	}
}

int	print_unsigned_decimal(const char *s, unsigned int n)
{
	t_vars			vars;
	int				digit_len;

	initialise_t_vars(&vars);
	check_flags_unsigned_decimal(s, &vars);
	digit_len = digits_count(n);
	if (n == 0 && vars.precision == 0)
		digit_len = 0;
	if (vars.precision >= 0 && vars.precision < digit_len)
		vars.precision = digit_len;
	else if (vars.precision < 0)
		vars.precision = digit_len;
	if (vars.mode != 1 && vars.mode != 3 && vars.width > vars.precision)
		print_padding(' ', vars.width - vars.precision);
	if (vars.mode == 3 && vars.width > vars.precision)
		print_padding('0', vars.width - vars.precision);
	print_padding('0', vars.precision - digit_len);
	if (!(n == 0 && vars.precision == 0))
		put_unsignednbr_fd(n, 1);
	if (vars.mode == 1 && vars.width > vars.precision)
		print_padding(' ', vars.width - vars.precision);
	if (vars.width > vars.precision)
		return (vars.width);
	return (vars.precision);
}

// int	main(void)
// {
// 	print_unsigned_decimal(".5u", 128);
// }