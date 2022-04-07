/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:39:27 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:39:28 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern t_conf	g_sh;

void	init_blt(t_blt *blt)
{
	blt->opt = 0;
	blt->up_flag = 0;
}

void	set_lower(char *cmd, t_blt *blt)
{
	int		i;

	if (cmd == NULL)
		return ;
	i = 0;
	while (cmd[i])
	{
		if ((cmd[i] >= 65) && (cmd[i] <= 90))
		{
			cmd[i] += 32;
			blt->up_flag = 1;
		}
		i++;
	}
}
