/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:25:38 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:25:39 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_free_single(void *ptr)
{
	if (!ptr)
		return (-1);
	free(ptr);
	ptr = NULL;
	return (1);
}

int	ft_free_double(void **ptr)
{
	int	i;

	if (!ptr)
		return (-1);
	i = -1;
	while (ptr[++i] != NULL)
		free(ptr[i]);
	free(ptr);
	ptr = NULL;
	return (1);
}
