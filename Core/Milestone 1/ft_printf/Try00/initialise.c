/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 12:03:25 by zheng             #+#    #+#             */
/*   Updated: 2026/08/05 01:43:39 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialise_t_vars(t_vars *vars)
{
	vars->mode = 0;
	vars->width = 0;
	vars->precision = -1;
	vars->prefix = 0;
	vars->is_upper = -1;
}
