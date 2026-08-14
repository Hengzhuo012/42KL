/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:24:34 by zheng             #+#    #+#             */
/*   Updated: 2026/08/05 21:58:52 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *s, ...);

int	print_char(int c);
int	print_string(char *str);
int	print_hexa_pointer(void *ptr);
int	print_decimal(int n);
int	print_unsigned_decimal(unsigned int n);
int	print_hexa_number(unsigned int n, int is_upper);

#endif