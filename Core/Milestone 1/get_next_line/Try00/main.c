/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 18:48:24 by madinata          #+#    #+#             */
/*   Updated: 2026/08/05 14:53:44 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*cur;

	if (argc != 2)
		return (printf("give one file name\n"), 1);
	if (argv[1][0] == '*')
		fd = STDIN_FILENO;
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (printf("can't read\n"), 1);
	}
	cur = get_next_line(fd);
	while (cur != NULL)
	{
		printf("%s\n", cur);
		free(cur);
		cur = get_next_line(fd);
	}
}
