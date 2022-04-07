/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:27:35 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:27:36 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srcsize;
	size_t	dstsize;
	size_t	count;

	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	i = dstsize;
	if (size <= dstsize)
		return (srcsize + size);
	count = size - dstsize - 1;
	while (count-- && *src)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dstsize + srcsize);
}
