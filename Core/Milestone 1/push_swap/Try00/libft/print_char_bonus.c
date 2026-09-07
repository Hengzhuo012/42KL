/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:01:06 by zheng             #+#    #+#             */
/*   Updated: 2026/08/05 21:19:07 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

//const char *s got the letter right after %
//char c got the first arg
//only cares about width (right align) and '-'

static void	check_flags_char(const char *s, t_vars *vars)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != 'c')
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
			if (vars->mode != 1)
				vars->mode = 2;
			get_width_and_update_index(s, &i, &vars->width);
		}
		else
			i++;
	}
}

int	print_char(const char *s, int c)
{
	t_vars	vars;

	initialise_t_vars(&vars);
	check_flags_char(s, &vars);
	if (vars.mode == 1)
		ft_putchar_fd(c, 1);
	if (vars.mode != 0 && vars.width > 1)
		print_padding(' ', vars.width - 1);
	if (vars.mode == 2 || vars.mode == 0)
		ft_putchar_fd(c, 1);
	if (vars.width > 1)
		return (vars.width);
	return (1);
}

// int	main(void)
// {
// 	print_char("-5c", 'c');
// }
