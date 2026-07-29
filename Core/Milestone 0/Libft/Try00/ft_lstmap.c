/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:46:09 by zheng             #+#    #+#             */
/*   Updated: 2026/07/29 21:02:17 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	start = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new_node);
		lst = lst->next;
	}
	return (start);
}
/*
void	*add_one(void *content)
{
	int	*ptr;
	int	*new_ptr;

	ptr = (int *)content;
	new_ptr = malloc(sizeof(int));
	if (!new_ptr)
		return (NULL);
	*new_ptr = *ptr + 1;
	return ((void *)new_ptr);
}

#include <stdio.h>
void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list;
	t_list	*new_list;
	int		*n1;
	int		*n2;

	n1 = malloc(sizeof(int));
	*n1 = 5;
	n2 = malloc(sizeof(int));
	*n2 = 10;

	list = ft_lstnew(n1);
	ft_lstadd_back(&list, ft_lstnew(n2));

	new_list = ft_lstmap(list, add_one, del);

	printf("%d\n", *(int *)new_list->content);
	printf("%d\n", *(int *)new_list->next->content);

	ft_lstclear(&list, del);
	ft_lstclear(&new_list, del);
	return (0);
}
*/