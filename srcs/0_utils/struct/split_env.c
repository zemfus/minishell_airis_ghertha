/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:36:54 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:36:55 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**split_env(char *env)
{
	char	**ret;
	int		i;

	i = -1;
	if (!env)
		return (NULL);
	ret = malloc(sizeof(char *) * 3);
	while (env[++i])
	{
		if (env[i] == '=' && env[i + 1] != '\0')
		{
			ret[0] = ft_strrdup(env, 0, i - 1);
			ret[1] = ft_strrdup(env, i + 1, ft_strlen(env) - 1);
			ret[2] = NULL;
			break ;
		}
		else if (env[i] == '=' && env[i + 1] == '\0')
		{
			ret[0] = ft_strrdup(env, 0, i - 1);
			ret[1] = NULL;
			ret[2] = NULL;
			break ;
		}
	}
	return (ret);
}
