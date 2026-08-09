/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:17:23 by zheng             #+#    #+#             */
/*   Updated: 2026/08/10 00:31:10 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_len(char *content)
{
	size_t	i;

	if (!content)
		return (0);
	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	return (i);
}

void	add_buffer_to_line(char *buffer, size_t buffer_len,
t_len_and_string *line)
{
	size_t	i;
	char	*new_content;

	new_content = malloc(sizeof(char) * (line->len + buffer_len + 1));
	if (!new_content)
		return ;
	i = 0;
	while (i < line->len)
	{
		new_content[i] = line->content[i];
		i++;
	}
	i = 0;
	while (i < buffer_len)
	{
		new_content[line->len + i] = buffer[i];
		i++;
	}
	new_content[line->len + buffer_len] = '\0';
	free(line->content);
	line->content = new_content;
	line->len += buffer_len;
}

char	*get_next_line(int fd)
{
	static char			buffer[BUFFER_SIZE + 1];
	ssize_t				bytes_read;
	size_t				chunk_len;
	t_len_and_string	line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line.content = NULL;
	line.len = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		chunk_len = get_len(buffer);
		add_buffer_to_line(buffer, chunk_len, &line);
		if (buffer[chunk_len - 1] == '\n')
			break ;
	}
	return (line.content);
}
