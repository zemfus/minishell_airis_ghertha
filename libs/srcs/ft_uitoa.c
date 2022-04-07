/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:28:52 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:28:53 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arr_size(unsigned int n)
{
	int		count;

	count = 1;
	while (1)
	{
		if (n / 10 == 0)
			break ;
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	char	*dst;
	int		dstsize;

	dstsize = arr_size(n) + 1;
	dst = malloc(sizeof(char) * dstsize);
	dst[--dstsize] = '\0';
	while (1)
	{
		dst[--dstsize] = n % 10 + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	return (dst);
}
