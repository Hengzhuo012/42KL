/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 10:46:11 by zheng             #+#    #+#             */
/*   Updated: 2026/08/15 01:08:28 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	initialise_buffer(t_line *buffer)
{
	buffer->content = NULL;
	buffer->len = 0;
	buffer->start = 0;
}

size_t	get_len(t_line *buffer)
{
	size_t	i;

	i = buffer->start;
	while (i < buffer->len && buffer->content[i] != '\n')
		i++;
	if (i < buffer->len && buffer->content[i] == '\n')
		i++;
	return (i);
}
