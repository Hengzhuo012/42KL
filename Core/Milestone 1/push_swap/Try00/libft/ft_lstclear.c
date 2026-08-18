/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:12:08 by zheng             #+#    #+#             */
/*   Updated: 2026/07/29 18:22:35 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_node;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	current_node = *lst;
	while (current_node)
	{
		next_node = current_node->next;
		del(current_node->content);
		free(current_node);
		current_node = next_node;
	}
	*lst = NULL;
}
/*
#include <stdio.h>

void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*start;
	t_list	*current;
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = malloc(1 * sizeof(char));
	str1[0] = 'a';
	str2 = malloc(1 * sizeof(char));
	str2[0] = 'b';
	str3 = malloc(1 * sizeof(char));
	str3[0] = 'c';
	start = ft_lstnew(str1);
	ft_lstadd_back(&start, ft_lstnew(str2));
	ft_lstadd_back(&start, ft_lstnew(str3));
	printf("Before:\n");
	current = start;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&(start->next), del);
	printf("After:\n");
	current = start;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&start, del);
	return (0);
}
*/