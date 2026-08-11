/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 00:09:44 by zheng             #+#    #+#             */
/*   Updated: 2026/08/12 00:16:54 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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