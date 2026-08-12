/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 00:01:09 by zheng             #+#    #+#             */
/*   Updated: 2026/08/12 00:18:07 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

//1024 -> soft limit
//10240 -> macOS limit
//1048576 -> hard limit

# ifndef MAX_FD
#  define MAX_FD 10240
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

#endif
