/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:17:23 by zheng             #+#    #+#             */
/*   Updated: 2026/08/10 11:50:45 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_len(char *content, size_t start)
{
	size_t	i;

	if (!content)
		return (0);
	i = start;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	return (i);
}

static void	add_buffer_to_line(const char *buffer_content,
size_t start, size_t end, t_line *line)
{
	size_t	i;
	char	*new_content;
	size_t	chunk_len;

	chunk_len = end - start;
	new_content = malloc(sizeof(char) * (line->len + chunk_len + 1));
	if (!new_content)
	{
		free(line->content);
		line->content = NULL;
		return ;
	}
	i = -1;
	while (++i < line->len)
		new_content[i] = line->content[i];
	i = -1;
	while (++i < chunk_len)
		new_content[line->len + i] = buffer_content[i];
	new_content[line->len + chunk_len] = '\0';
	free(line->content);
	line->content = new_content;
	line->len += chunk_len;
}

static ssize_t	fill_buffer(int fd, t_line *buffer)
{
	ssize_t	bytes;

	if (!buffer->content)
	{
		buffer->content = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer->content)
			return (-1);
	}
	bytes = read(fd, buffer->content, BUFFER_SIZE);
	if (bytes > 0)
	{
		buffer->len = (size_t)bytes;
		buffer->content[buffer->len] = '\0';
		buffer->start = 0;
	}
	else if (bytes < 0)
	{
		free(buffer->content);
		buffer->content = NULL;
		buffer->len = 0;
		buffer->start = 0;
	}
	return (bytes);
}

static int	check_buffer(int fd, t_line *buffer, t_line *line)

char	*get_next_line(int fd)
{
	static t_line	buffer = {0, 0, 0, NULL};
	t_line			line;
	ssize_t			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line.content = NULL;
	line.len = 0;
	while (!line.content
		|| (line.len > 0 && line.content[buffer.len - 1] != '\n'))
	{
		if (buffer.len >= 0 && buffer.start == buffer.len)
		{
			bytes = fill_buffer(fd, &buffer);
			if (bytes < 0 || (bytes == 0 && line.len == 0))
			{
				free(line.content);
				return (NULL);
			}
			if (bytes == 0)
				break ;
		}
		buffer.end = get_len(buffer.content, buffer.start);
		add_buffer_to_line(buffer.content, buffer.len, &line);
		if (!line.content)
			return (NULL);
		buffer.start = buffer.end;
	}
	return (line.content);
}
