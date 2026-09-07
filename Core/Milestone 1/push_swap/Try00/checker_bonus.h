/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namak <namak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:29:03 by namak             #+#    #+#             */
/*   Updated: 2026/09/07 15:53:00 by namak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

int		check_inputs_bonus(char **argv);
int		is_operations(char *str);
int		is_sorted(t_list *stack);

void	sa_b(t_list **a, t_list **b);
void	sb_b(t_list **a, t_list **b);
void	ss_b(t_list **a, t_list **b);
void	pa_b(t_list **a, t_list **b);
void	pb_b(t_list **a, t_list **b);
void	ra_b(t_list **a, t_list **b);
void	rb_b(t_list **a, t_list **b);
void	rr_b(t_list **a, t_list **b);
void	rra_b(t_list **a, t_list **b);
void	rrb_b(t_list **a, t_list **b);
void	rrr_b(t_list **a, t_list **b);
#endif
