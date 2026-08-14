/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:17:28 by zheng             #+#    #+#             */
/*   Updated: 2026/08/14 23:07:59 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_line
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*content;
}	t_line;

char	*get_next_line(int fd);
void	initialise_buffer(t_line *buffer);
size_t	get_len(t_line *buffer);

#endif