/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:45:20 by zheng             #+#    #+#             */
/*   Updated: 2026/07/29 13:07:47 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
/*
#include <stdio.h>
int main(void)
{
	t_list *head;

	head = ft_lstnew("Node 2");
	ft_lstadd_front(&head, ft_lstnew("Node 1"));
    printf("Size: %d\n", ft_lstsize(head));
}
*/