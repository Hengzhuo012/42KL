/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:42:54 by zheng             #+#    #+#             */
/*   Updated: 2026/08/24 18:03:47 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_flag
{
	int	strat;
	int	bench;
}	t_flag;

typedef struct s_opt
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_opt;

int		check_inputs(char **argv, t_flag *flags);

void	init_t_opt(t_opt *opt);
void	init_t_flag(t_flag *flags);
void	print_error(void);
void	print_bench(t_flag *flags, t_opt *opt, double disorder);

void	simple_sort(t_flag *flags, t_list **stack, t_opt *opt);
void	medium_sort(t_flag *flags, t_list **stack, t_opt *opt);
void	complex_sort(t_flag *flags, t_list **stack, t_opt *opt);

void	sa(t_list **a, t_list **b, t_flag *flags, t_opt *opt);
void	sb(t_list **a, t_list **b, t_flag *flags, t_opt *opt);
void	ss(t_list **a, t_list **b, t_flag *flags, t_opt *opt);
void	pa(t_list **a, t_list **b, t_flag *flags, t_opt *opt);
void	pb(t_list **a, t_list **b, t_flag *flags, t_opt *opt);
void	ra(t_list **a, t_list **b, t_flag *flags, t_opt *opt);
void	rb(t_list **a, t_list **b, t_flag *flags, t_opt *opt);
void	rr(t_list **a, t_list **b, t_flag *flags, t_opt *opt);
void	rra(t_list **a, t_list **b, t_flag *flags, t_opt *opt);
void	rrb(t_list **a, t_list **b, t_flag *flags, t_opt *opt);
void	rrr(t_list **a, t_list **b, t_flag *flags, t_opt *opt);

int		medium_sqrt(int n);
int		get_rank(t_list *stack, t_list *bucket, int val);
int		get_max_pos(t_list *bucket);

#endif