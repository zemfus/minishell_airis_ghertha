/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:24:13 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:24:14 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*last_add;

	if (!lst || !new_lst)
		return ;
	if (!*lst)
	{
		*lst = new_lst;
		return ;
	}
	last_add = ft_lstlast(*lst);
	last_add->next = new_lst;
}
