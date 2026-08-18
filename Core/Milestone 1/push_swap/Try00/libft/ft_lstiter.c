/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:23:14 by zheng             #+#    #+#             */
/*   Updated: 2026/07/29 18:41:01 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>
void	f(void *content)
{
	char	*str;

	str = (char *)content;
	printf("%s\n", str);
}

int	main(void)
{
	t_list	*start;
	t_list	*next;

	start = ft_lstnew("Node 1");
	ft_lstadd_back(&start, ft_lstnew("Node 2"));
	ft_lstiter(start, f);
	while (start)
	{
		next = start->next;
		free(start);
		start = next;
	}
}
*/