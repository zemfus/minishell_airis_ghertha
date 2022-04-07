/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:25:24 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:25:25 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *ptr, int val, size_t num)
{
	unsigned char	*ptr_tmp;

	ptr_tmp = (unsigned char *)ptr;
	while (num--)
	{
		if (*ptr_tmp == (unsigned char)val)
			return (ptr_tmp);
		ptr_tmp++;
	}
	return (NULL);
}
