/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:35:10 by zheng             #+#    #+#             */
/*   Updated: 2026/07/29 16:11:56 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
//need to test with valgrind
#include <stdio.h>
void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*start;
	char	*str;

	str = malloc(1 * sizeof(char));
	str[0] = 'c';
	start = ft_lstnew(str);
	printf("Before: %s\n", (char *)start->content);
	ft_lstdelone(start, del);
}
*/