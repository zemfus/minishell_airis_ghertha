/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:25:29 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:25:30 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*ptr1_tmp;
	unsigned char	*ptr2_tmp;

	ptr1_tmp = (unsigned char *)ptr1;
	ptr2_tmp = (unsigned char *)ptr2;
	while (num--)
	{
		if (*ptr1_tmp != *ptr2_tmp)
			return (*ptr1_tmp - *ptr2_tmp);
		ptr1_tmp++;
		ptr2_tmp++;
	}
	return (0);
}
