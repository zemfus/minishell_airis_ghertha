/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:17:48 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:17:49 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_sign(char c, long long *sign, int *i)
{
	if (c == '-')
		*sign = -1;
	else
		*sign = 1;
	*i = *i + 1;
}

long long	ft_atol(char *str)
{
	int			i;
	long long	sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		set_sign(str[i], &sign, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (long long)(str[i] - '0');
		i++;
		if (result == 922337203685477580 && sign == -1 && str[i] >= '8')
			return (0);
		if (result >= 9223372036854775807 && sign == 1)
			return (-1);
	}
	return (result * sign);
}
