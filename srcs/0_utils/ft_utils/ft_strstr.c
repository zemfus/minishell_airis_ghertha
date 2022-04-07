/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:31:58 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:31:59 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_strstr(char *str, char *src)
{
	int	i;

	i = -1;
	if (!str || !src)
		return (NULL);
	while (str[++i])
	{
		if (str[i] == src[0])
		{
			if ((ft_strncmp(&str[i], src, ft_strlen(src))) == 0)
				return (&str[i]);
		}
	}
	return (NULL);
}
