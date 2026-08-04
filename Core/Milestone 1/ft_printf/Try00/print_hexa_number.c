/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 01:08:33 by zheng             #+#    #+#             */
/*   Updated: 2026/08/05 02:13:56 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
(mode 0)
%x

(mode 1)
%-(width)x -> padding with ending ' ', left-aligned

(mode 2)
%(width)x -> padding with leading ' ', right-aligned

(mode 3)
%0(width)x -> peadding with leading '0', right-aligned

(precision)
%.(precision)x -> min number of (0-padded) digits to output
					%.0x, x = 0, output = (empty)
					ignore 0 flag

(prefix '#')
%#x -> print '0x' prefix if number != 0
		'0x' counts towards width
*/

#include "ft_printf.h"

static int	count_hexa_length(unsigned int n)
{
	int	len_hexa_ptr;

	len_hexa_ptr = 1;
	while (n >= 16)
	{
		len_hexa_ptr++;
		n /= 16;
	}
	return (len_hexa_ptr);
}

static void	print_unsigned_decimal_in_hexa(unsigned int n, int len_hexa_ptr,
int is_upper)
{
	char		buffer[16];
	char		*hexa;
	int			i;

	if (is_upper)
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	i = len_hexa_ptr - 1;
	while (i >= 0)
	{
		buffer[i] = hexa[n % 16];
		n /= 16;
		i--;
	}
	i = 0;
	while (i < len_hexa_ptr)
		ft_putchar_fd(buffer[i++], 1);
}

static void	check_flags_hexa_number(const char *s, t_vars *vars, unsigned int n)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != 'x' && s[i] != 'X')
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
		else if (s[i] == '#' && n != 0)
			vars->prefix = s[i++];
		else
			i++;
	}
}

static void	render_hexa_number_output(t_vars *vars, int hexa_num_len,
int print_len, unsigned int n)
{
	if (vars->mode != 1 && vars->mode != 3 && vars->width > print_len)
		print_padding(' ', vars->width - print_len);
	if (vars->prefix && vars->is_upper)
		ft_putstr_fd("0X", 1);
	else if (vars->prefix)
		ft_putstr_fd("0x", 1);
	if (vars->mode == 3 && vars->width > print_len)
		print_padding('0', vars->width - print_len);
	print_padding('0', vars->precision - hexa_num_len);
	if (!(n == 0 && vars->precision == 0))
		print_unsigned_decimal_in_hexa(n, hexa_num_len);
	if (vars->mode == 1 && vars->width > print_len)
		print_padding(' ', vars->width - print_len);
}

int	print_hexa_number(const char *s, unsigned int n, int is_upper)
{
	t_vars			vars;
	int				hexa_num_len;
	int				print_len;

	initialise_t_vars(&vars);
	vars.is_upper = is_upper;
	check_flags_hexa_number(s, &vars, n);
	hexa_num_len = count_hexa_length(n);
	if (n == 0 && vars.precision == 0)
		hexa_num_len = 0;
	if (vars.precision >= 0)
	{
		if (vars.precision < hexa_num_len)
			vars.precision = hexa_num_len;
		if (vars.mode != 1)
			vars.mode = 2;
	}
	else
		vars.precision = hexa_num_len;
	print_len = vars.precision + (vars.prefix != 0) * 2;
	render_hexa_number_output(vars, hexa_num_len, print_len, n);
	if (vars.width > print_len)
		return (vars.width);
	return (print_len);
}

// int	main(void)
// {
// 	print_hexa_number("x", 127, 0);
// }