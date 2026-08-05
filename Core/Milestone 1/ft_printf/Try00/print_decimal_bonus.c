/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 22:14:30 by zheng             #+#    #+#             */
/*   Updated: 2026/08/05 21:19:10 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
(mode 0)
%d

(mode 1)
%-(width)d -> padding with ending ' ', left-aligned
				only if width > length else ignore
				if %-5d, d = -42, output = "-42  "

(mode 2)
%(width)d -> padding with leading ' ', right-aligned
				only if width > length else ignore
				if %5d, d = -42, output = "  -42"

(mode 3)
%0(width)d -> padding with leading '0', right-aligned
				only if width > length else ignore
				if %05d, d = -42, output = "-0042"

(precision)
%.(precision)d -> min number of digits to output
					%.5d, d = -42, output = "-00042"
					%.0d, ignore precision
					%.0d, d = 0, output = (empty)
					ignore 0 flag

(prefix '-')
if n < 0

(prefix '+')
%+d -> print '+' prefix if number not negative
		overwrite ' ' flag

(prefix ' ')
% d -> print ' ' prefix if number not negative
*/
#include "ft_printf_bonus.h"

static void	determine_prefix_and_update_index(const char *s, int *i,
int *prefix)
{
	if (s[*i] == '+')
		*prefix = '+';
	else if (s[*i] == ' ' && (*prefix) != '+')
		*prefix = ' ';
	(*i)++;
}

static void	check_flags_decimal(const char *s, t_vars *vars)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != 'd' && s[i] != 'i')
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
		else if (s[i] == '+' || s[i] == ' ')
			determine_prefix_and_update_index(s, &i, &vars->prefix);
		else
			i++;
	}
}

static void	render_decimal_output(t_vars *vars, int digit_len,
int print_len, unsigned int num)
{
	if (vars->mode != 1 && vars->mode != 3 && vars->width > print_len)
		print_padding(' ', vars->width - print_len);
	if (vars->prefix)
		ft_putchar_fd(vars->prefix, 1);
	if (vars->mode == 3 && vars->width > print_len)
		print_padding('0', vars->width - print_len);
	print_padding('0', vars->precision - digit_len);
	if (!(num == 0 && vars->precision == 0))
		put_unsignednbr_fd(num, 1);
	if (vars->mode == 1 && vars->width > print_len)
		print_padding(' ', vars->width - print_len);
}

static unsigned int	convert_int_to_unsigned_int(int n, t_vars *vars)
{
	if (n < 0)
	{
		vars->prefix = '-';
		return ((unsigned int)(-(long)n));
	}
	return ((unsigned int)n);
}

int	print_decimal(const char *s, int n)
{
	t_vars			vars;
	int				digit_len;
	int				print_len;
	unsigned int	num;

	initialise_t_vars(&vars);
	check_flags_decimal(s, &vars);
	num = convert_int_to_unsigned_int(n, &vars);
	digit_len = digits_count(num);
	if (n == 0 && vars.precision == 0)
		digit_len = 0;
	if (vars.precision >= 0)
	{
		if (vars.precision < digit_len)
			vars.precision = digit_len;
		if (vars.mode != 1)
			vars.mode = 2;
	}
	else
		vars.precision = digit_len;
	print_len = vars.precision + (vars.prefix != 0);
	render_decimal_output(&vars, digit_len, print_len, num);
	if (vars.width > print_len)
		return (vars.width);
	return (print_len);
}

// int	main(void)
// {
// 	char	*test;
// 	int		n;

// 	test = " 05d";
// 	n = 42;
// 	print_decimal(test, n);

// }