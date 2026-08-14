/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 00:00:41 by zheng             #+#    #+#             */
/*   Updated: 2026/08/12 00:17:26 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		new_content[line->len + i] = buffer_content[start + i];
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
{
	ssize_t	bytes;

	if (buffer->start == buffer->len)
	{
		bytes = fill_buffer(fd, buffer);
		if (bytes < 0 || (bytes == 0 && line->len == 0))
		{
			free(line->content);
			return (-1);
		}
		if (bytes == 0)
			return (0);
	}
	return (1);
}

//status = -1 if got error
//status = 0 if reach EOF and line got content
//status = 1 if buffer is valid and there is more left to fetch

char	*get_next_line(int fd)
{
	static t_line	buffer[MAX_FD];
	t_line			line;
	int				status;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	line.content = NULL;
	line.len = 0;
	while (!line.content
		|| (line.len > 0 && line.content[line.len - 1] != '\n'))
	{
		status = check_buffer(fd, &buffer[fd], &line);
		if (status == -1)
			return (NULL);
		if (status == 0)
			break ;
		buffer[fd].end = get_len(buffer[fd].content, buffer[fd].start);
		add_buffer_to_line(buffer[fd].content,
			buffer[fd].start, buffer[fd].end, &line);
		if (!line.content)
			return (NULL);
		buffer[fd].start = buffer[fd].end;
	}
	return (line.content);
}

/*
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*l1;
	char	*l2;
	char	*l3;

	fd1 = open("test", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	fd3 = open("test3", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		printf("Error opening files");
		return (1);
	}
	l1 = get_next_line(fd1);
	l2 = get_next_line(fd2);
	l3 = get_next_line(fd3);
	while (l1 || l2 || l3)
	{
		if (l1)
		{
			printf("FD 1: %s", l1);
			free(l1);
			l1 = get_next_line(fd1);
		}
		if (l2)
		{
			printf("FD 2: %s", l2);
			free(l2);
			l2 = get_next_line(fd2);
		}
		if (l3)
		{
			printf("FD 3: %s", l3);
			free(l3);
			l3 = get_next_line(fd3);
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/
