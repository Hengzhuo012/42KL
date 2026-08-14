/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:32:53 by zheng             #+#    #+#             */
/*   Updated: 2026/08/14 23:07:53 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
