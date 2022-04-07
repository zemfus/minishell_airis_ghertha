/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:37:51 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:37:52 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	exit_hdoc(char **file, int ret)
{
	free(*file);
	return (ret);
}

char	*make_hdoc_file_name(int i)
{
	char	*hdoc;
	char	*num;

	hdoc = ft_strdup(".hdoc");
	num = ft_itoa(i);
	hdoc = ft_strcjoin(hdoc, num, '_');
	if (num)
		free(num);
	return (hdoc);
}

void	close_redir_fd(t_redirect *redir)
{
	close(redir->fd);
	redir->fd = 0;
}
