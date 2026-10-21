/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:40:34 by zheng             #+#    #+#             */
/*   Updated: 2026/07/23 15:41:13 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

void	ft_print(char *array, int size)
{
	int	i;

	i = 0;
	while (i < size * size)
	{
		write(1, &array[i], 1);
		if (i % size != size - 1)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
		i++;
	}
}
