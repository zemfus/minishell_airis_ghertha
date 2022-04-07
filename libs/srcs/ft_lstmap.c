/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:25:00 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:25:01 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_data;

	if (!lst || !f)
		return (NULL);
	new_node = NULL;
	while (lst)
	{
		new_data = ft_lstnew(f(lst->content));
		if (!new_data)
		{
			ft_lstclear(&new_data, del);
			break ;
		}
		ft_lstadd_back(&new_node, new_data);
		lst = lst->next;
	}
	return (new_node);
}
