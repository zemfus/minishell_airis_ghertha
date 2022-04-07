/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:37:48 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:37:49 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern t_conf	g_sh;

static void	set_parent_signal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

static void	set_child_singal(void)
{
	signal(SIGINT, hdoc_sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

static int	write_text(int fd[2], int hdoc_fd)
{
	char	*ret;
	int		eof;
	int		status;

	eof = -1;
	set_parent_signal();
	close(fd[WRITE]);
	wait(&status);
	if (!(WIFEXITED(status)))
		exit(1);
	if (status == 256)
		return (1);
	while (eof != 0)
	{
		eof = get_next_line(fd[READ], &ret);
		if (eof == -1)
			return (-1);
		ret = ft_strjoin(ret, "\n");
		if (eof > 0)
			write(hdoc_fd, ret, ft_strlen(ret));
		free(ret);
		ret = NULL;
	}
	close(fd[READ]);
	return (0);
}

static void	receive_text(int fd[2], char *delimeter)
{
	char	*line;

	line = NULL;
	close(fd[READ]);
	while (1)
	{
		set_child_singal();
		line = readline("> ");
		if (!line || ((ft_strcmp(line, delimeter)) == 0))
		{
			if (!line)
				move_cursor(NULL, 1, 2);
			if (line)
				free(line);
			close(fd[WRITE]);
			exit(0);
		}
		if (line != NULL)
		{
			write(fd[WRITE], line, ft_strlen(line));
			write(fd[WRITE], "\n", 1);
			free(line);
		}
	}
	close(fd[WRITE]);
}

int	exec_heredoc(char *delimeter, int hdoc_fd)
{
	int		ret;
	pid_t	pid;
	int		fd[2];

	ret = 0;
	pipe(fd);
	pid = fork();
	if (pid > 0)
		ret = write_text(fd, hdoc_fd);
	else if (pid == 0)
		receive_text(fd, delimeter);
	g_sh.exit_status = ret;
	return (ret);
}
