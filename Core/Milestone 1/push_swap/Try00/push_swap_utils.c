/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namak <namak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:24:46 by namak             #+#    #+#             */
/*   Updated: 2026/09/07 09:10:00 by namak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_list *stack)
{
	t_list	*stack_cpy;
	int		mistakes;
	int		pairs;

	mistakes = 0;
	pairs = 0;
	while (stack)
	{
		stack_cpy = stack->next;
		while (stack_cpy)
		{
			pairs++;
			if ((long int)stack->content > (long int)stack_cpy->content)
				mistakes++;
			stack_cpy = stack_cpy->next;
		}
		stack = stack->next;
	}
	if (pairs == 0)
		return (0);
	return ((double)mistakes / pairs);
}

char	**create_args(int argc, char **argv)
{
	char	*joined;
	char	*temp;
	char	**args;
	int		i;

	joined = ft_strdup("dummy ");
	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin(joined, argv[i]);
		free(joined);
		joined = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	args = ft_split(joined, ' ');
	free(joined);
	return (args);
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	allocation_error(void)
{
	print_error();
	return (1);
}

void	del_nothing(void *content)
{
	(void)content;
}
