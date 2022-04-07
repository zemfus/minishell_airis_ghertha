/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:28:01 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:28:02 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnrcmp(char *s1, char *s2, int cnt)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2 || cnt <= 0 || i + 1 < cnt || j + 1 < cnt)
		return (-1);
	while (cnt && i >= 0 && j >= 0)
	{
		if (!s1[i] || !s2[j])
			break ;
		if (s1[i] == s2[j])
		{
			i--;
			j--;
		}
		else if (s1[i] != s2[j])
			return (-1);
		cnt--;
	}
	if (cnt == 0)
		return (0);
	return (-1);
}
