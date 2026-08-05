/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:12:40 by zheng             #+#    #+#             */
/*   Updated: 2026/08/05 14:06:53 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
(mode 0)
%p -> output 0x followed by hex address in lowercase

(mode 2)
%(width)p -> padding with ending ' ', right-aligned
				only if width > length else ignore

(mode 1)
%-(width)p -> padding with leading ' ', left-aligned
				only if width > length else ignore

(mode 3)
%0(width)p -> error
*/

#include "ft_printf.h"

static int	count_hexa_length(void *ptr)
{
	unsigned long long	nbr;
	int					len_hexa_ptr;

	if (!ptr)
		return (5);
	nbr = (unsigned long long)ptr;
	len_hexa_ptr = 1;
	while (nbr >= 16)
	{
		len_hexa_ptr++;
		nbr /= 16;
	}
	return (len_hexa_ptr);
}

static void	print_decimal_in_hexa(void *ptr, int len_hexa_ptr)
{
	unsigned long long	nbr;
	char				buffer[16];
	char				*hexa;
	int					i;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return ;
	}
	ft_putstr_fd("0x", 1);
	nbr = (unsigned long long)ptr;
	hexa = "0123456789abcdef";
	i = len_hexa_ptr - 1;
	while (i >= 0)
	{
		buffer[i] = hexa[nbr % 16];
		nbr /= 16;
		i--;
	}
	i = 0;
	while (i < len_hexa_ptr)
		ft_putchar_fd(buffer[i++], 1);
}

static void	check_flags_hexa_pointer(const char *s, t_vars *vars)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != 'p')
	{
		if (s[i] == '.')
			skip_precision(s, &i);
		else if (s[i] == '-')
		{
			vars->mode = 1;
			i++;
		}
		else if (ft_isdigit(s[i]))
		{
			if (vars->mode != 1 && s[i] != '0')
				vars->mode = 2;
			else if (vars->mode != 1)
				vars->mode = 3;
			get_width_and_update_index(s, &i, &vars->width);
		}
		else
			i++;
	}
}

static void	print_hexa_pointer_mode(void *ptr, t_vars *vars, int total_len)
{
	int	len_hexa_ptr;

	len_hexa_ptr = count_hexa_length(ptr);
	if (vars->mode == 1)
	{
		print_decimal_in_hexa(ptr, len_hexa_ptr);
		if (vars->width > total_len)
			print_padding(' ', vars->width - total_len);
	}
	else if (vars->mode == 2 || vars->mode == 3)
	{
		if (vars->width > total_len)
			print_padding(' ', vars->width - total_len);
		print_decimal_in_hexa(ptr, len_hexa_ptr);
	}
	else
		print_decimal_in_hexa(ptr, len_hexa_ptr);
}

int	print_hexa_pointer(const char *s, void *ptr)
{
	t_vars	vars;
	int		total_len;

	initialise_t_vars(&vars);
	check_flags_hexa_pointer(s, &vars);
	if (!ptr)
		total_len = 5;
	else
		total_len = count_hexa_length(ptr) + 2;
	if (vars.mode == 3)
		return (0);
	print_hexa_pointer_mode(ptr, &vars, total_len);
	if (vars.width > total_len)
		return (vars.width);
	return (total_len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	i = 10;
// 	int	*ptr = &i;

// 	write(1, "Without flags:", ft_strlen("Without flags:"));
// 	print_hexa_pointer("p", ptr);
// 	ft_putchar_fd('\n', 1);

// 	print_hexa_pointer("20p", ptr);
// 	ft_putchar_fd('\n', 1);
// 	print_hexa_pointer("-20p", ptr);
// 	ft_putchar_fd('\n', 1);
// 	print_hexa_pointer("020p", ptr);
// 	ft_putchar_fd('\n', 1);
// }