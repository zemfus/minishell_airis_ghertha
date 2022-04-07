/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:28:33 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:28:34 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	buffer_size;
	char	*result;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (s1[start] == '\0')
	{
		result = malloc(sizeof(char) * 1);
		result[0] = '\0';
		return (result);
	}
	end = ft_strlen(s1) - 1;
	while (s1[end] && ft_strchr(set, s1[end]))
		end--;
	buffer_size = end - start + 1;
	result = malloc(sizeof(char) * (buffer_size + 1));
	ft_strlcpy(result, &s1[start], buffer_size + 1);
	return (result);
}
