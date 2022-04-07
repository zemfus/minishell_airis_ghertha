/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:31:46 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:31:47 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_str_change(char *str, char *src, int st, int ed)
{
	char	*ret;

	if (!str || !src || st < 0 || ed < 0)
		return (NULL);
	ret = NULL;
	if (st == -1 && ed == -1)
		return (NULL);
	if (st == 0)
	{
		ret = ft_strdup(src);
		ret = ft_strjoin(ret, &str[ed + 1]);
	}
	else
	{
		ret = ft_strrdup(str, 0, st - 1);
		ret = ft_strjoin(ret, src);
		ret = ft_strjoin(ret, &str[ed + 1]);
	}
	free(str);
	return (ret);
}
