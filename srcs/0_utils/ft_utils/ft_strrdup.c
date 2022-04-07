/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:31:55 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:31:56 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_strrdup(char *s, int st, int ed)
{
	int		i;
	char	*ret;
	int		dst_len;
	int		src_len;

	i = 0;
	dst_len = ed - st + 1;
	src_len = ft_strlen(s);
	if (!s || dst_len > src_len)
		return (NULL);
	ret = malloc(sizeof(char) * dst_len + 1);
	while (st <= ed)
	{
		ret[i] = s[st];
		i++;
		st++;
	}
	ret[i] = '\0';
	return (ret);
}
