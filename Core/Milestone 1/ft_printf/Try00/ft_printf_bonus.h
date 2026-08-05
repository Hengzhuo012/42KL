/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:23:53 by zheng             #+#    #+#             */
/*   Updated: 2026/08/05 21:18:59 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_vars
{
	int	mode;
	int	width;
	int	precision;
	int	prefix;
	int	is_upper;
}	t_vars;

int		ft_printf(const char *s, ...);

int		print_char(const char *s, int c);
int		print_string(const char *s, char *str);
int		print_decimal(const char *s, int n);
int		print_unsigned_decimal(const char *s, unsigned int n);
int		print_hexa_pointer(const char *s, void *ptr);
int		print_hexa_number(const char *s, unsigned int n, int upper);

int		is_conversion(char c);

void	skip_precision(const char *s, int *i);
void	get_width_and_update_index(const char *s, int *i, int *len);
void	print_padding(char c, int len);
int		get_precision(const char *s, int *i);

void	initialise_t_vars(t_vars *vars);

void	put_unsignednbr_fd(unsigned int n, int fd);
int		digits_count(unsigned int n);

#endif