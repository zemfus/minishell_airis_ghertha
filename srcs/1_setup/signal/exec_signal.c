/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:37:15 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:37:16 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	hdoc_sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		exit(1);
	}
}

void	exec_sigint(int signum)
{
	(void)signum;
	ft_putstr_fd("\n", 2);
	rl_on_new_line();
	exit(130);
}

void	exec_sigquit(int signum)
{
	(void)signum;
	ft_putstr_fd("Quit: 3\n", 2);
	exit(131);
}
