/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:18:13 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:18:14 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dest;
	size_t	total;
	size_t	i;

	total = count * size;
	dest = malloc(total);
	i = 0;
	while (total--)
	{
		dest[i] = 0;
		i++;
	}
	return ((void *)dest);
}
