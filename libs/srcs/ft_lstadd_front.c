/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:24:34 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:24:35 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_lst)
{
	if (lst && new_lst)
	{
		new_lst->next = *lst;
		*lst = new_lst;
	}
	else
		return ;
}
