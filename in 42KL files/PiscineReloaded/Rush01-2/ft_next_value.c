/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:49:27 by zheng             #+#    #+#             */
/*   Updated: 2026/07/23 15:00:56 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//used in ft_next_permutation
void	ft_swap(char *s1, char *s2)
{
	char	temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

//reversed when "1432" changed to "2134"
void	ft_reverse_order(char *str_row, int len)
{
	int		i;

	i = 0;
	while (i < len / 2)
	{
		ft_swap(&str_row[i], &str_row[len - 1 - i]);
		i++;
	}
}

//*out is also the input string like "1234"
//size is size of array which is 4 for base question
void	ft_next_permutation(char *out, int size)
{
	int	index;
	int	swap_index;

	swap_index = -1;
	index = size - 1;
	while (index > 0)
	{
		if (out[index] > out[index - 1])
		{
			swap_index = index - 1;
			break ;
		}
		index--;
	}
	index = size - 1;
	while (swap_index >= 0 && index >= 0)
	{
		if (out[swap_index] < out[index])
		{
			ft_swap(&(out[swap_index]), &(out[index]));
			ft_reverse_order(&(out[swap_index + 1]), size - swap_index - 1);
			break ;
		}
		index--;
	}
}

//check if the row is last combination, eg "4321"
//return 0 if it is last combination, else 1
//row is test value, size is 4 by default
int	is_last_comb(char *str_row, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str_row[i] - '0' != size - i)
			return (0);
		i++;
	}
	return (1);
}
