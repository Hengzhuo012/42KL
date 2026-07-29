/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:50:05 by zheng             #+#    #+#             */
/*   Updated: 2026/07/29 14:31:54 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*first_node;
	t_list	*next_node;

	first_node = ft_lstnew("Node 1");
	ft_lstadd_back(&first_node, ft_lstnew("Node 2"));
	ft_lstadd_back(&first_node, ft_lstnew("Node 3"));
	while (first_node)
	{
		printf("%s\n", (char *)first_node->content);
		next_node = first_node->next;
		free(first_node);
		first_node = next_node;
	}
	return (0);
}
*/