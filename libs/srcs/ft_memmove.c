/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:25:43 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:25:44 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	size_t	i;
	char	*dst_tmp;

	i = 0;
	dst_tmp = (char *)dst;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (num > 0)
		{
			dst_tmp[num - 1] = ((char *)src)[num - 1];
			num--;
		}
	}
	else
	{
		while (i < num)
		{
			dst_tmp[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
