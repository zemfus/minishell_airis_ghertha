/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_strjoin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:31:41 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:31:42 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**ft_double_strjoin(char **dst, char *src)
{
	char	**ret;
	int		size;
	int		i;

	i = -1;
	size = 0;
	ret = NULL;
	if (!dst)
	{
		ret = malloc(sizeof(char *) * 2);
		ret[0] = ft_strdup(src);
		ret[1] = NULL;
	}
	else if (dst)
	{
		size = ft_double_strlen((const char **)dst);
		ret = malloc(sizeof(char *) * (size + 2));
		while (dst[++i] != NULL)
			ret[i] = ft_strdup(dst[i]);
		ret[i] = ft_strdup(src);
		ret[i + 1] = NULL;
		ft_free_double((void **)dst);
	}
	return (ret);
}
