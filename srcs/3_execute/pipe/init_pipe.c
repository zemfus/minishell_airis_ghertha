/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:39:41 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:39:42 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern t_conf	g_sh;

void	run_in_child(int i, int cnt, int *fd_prev, t_process *proc_lst)
{
	return_terminal();
	signal(SIGINT, exec_sigint);
	signal(SIGQUIT, exec_sigquit);
	if (proc_lst->redir_err == 1)
		exit(1);
	if (i > 0)
	{
		dup2(*fd_prev, STDIN);
		close(g_sh.pipe.fd[0]);
	}
	if (i < (cnt - 1))
		dup2(g_sh.pipe.fd[1], STDOUT);
	else
		dup2(g_sh.fd_backup[1], STDOUT);
	blt_intro(proc_lst);
	exit(g_sh.exit_status);
}

void	run_in_parents(int i, int cnt, int *fd_prev, t_cmd *proc)
{
	int	status;

	(void)proc;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	wait(&status);
	set_terminal();
	g_sh.exit_status = WEXITSTATUS(status);
	if (!(WIFEXITED(status)))
		return ;
	if (i > 0)
		close(*fd_prev);
	*fd_prev = g_sh.pipe.fd[0];
	if (i == (cnt - 1))
		close(g_sh.pipe.fd[0]);
	close(g_sh.pipe.fd[1]);
}

int	redir_in_pipe(t_process *proc_lst)
{
	int	redir_prev;

	redir_prev = set_all_redir_lst(proc_lst);
	if (redir_prev)
	{
		g_sh.exit_status = 1;
		return (1);
	}
	return (0);
}

void	run_pipe(int cnt)
{
	int			i;
	int			fd_prev;
	t_cmd		*proc;
	t_process	*proc_lst;

	i = -1;
	proc_lst = g_sh.process->head;
	while (++i < cnt)
	{
		proc = proc_lst->cmd;
		if (i != (cnt - 1))
			pipe(g_sh.pipe.fd);
		redir_in_pipe(proc_lst);
		g_sh.pipe.pid[i] = fork();
		if (g_sh.pipe.pid[i] > 0)
			run_in_parents(i, cnt, &fd_prev, proc);
		else if (g_sh.pipe.pid[i] == 0)
			run_in_child(i, cnt, &fd_prev, proc_lst);
		else
			return ;
		proc_lst = proc_lst->next;
	}
}

void	pipe_intro(int cnt)
{
	g_sh.pipe.pid = malloc(sizeof(pid_t) * cnt);
	if (!(g_sh.pipe.pid))
		return ;
	g_sh.fd_backup[0] = dup(0);
	g_sh.fd_backup[1] = dup(1);
	run_pipe(cnt);
	dup2(g_sh.fd_backup[0], 0);
	ft_free_single((void *)g_sh.pipe.pid);
}
