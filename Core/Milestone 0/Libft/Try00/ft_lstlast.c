/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:13:30 by zheng             #+#    #+#             */
/*   Updated: 2026/07/29 14:34:04 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list	*lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
int main(void)
{
	t_list	*head;
	t_list	*last;
	t_list	*next_node;

	head = ft_lstnew("Node 3");
	ft_lstadd_front(&head, ft_lstnew("Node 2"));
	ft_lstadd_front(&head, ft_lstnew("Node 1"));
	last = ft_lstlast(head);
    printf("Last: %s\n", (char *)last->content);
	while (head)
	{
		next_node = head->next;
		free(head);
		head = next_node;
	}
}
*/