/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:37:24 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:37:25 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern t_conf	g_sh;

void	set_term_cursor(void)
{
	struct termios	cursor;

	tcgetattr(0, &cursor);
	cursor.c_lflag &= ~ICANON;
	cursor.c_lflag &= ~ECHO;
	tcsetattr(0, TCSANOW, &cursor);
}

int	set_term_default(int status)
{
	tcsetattr(0, TCSANOW, &g_sh.term);
	return (status);
}

void	set_terminal(void)
{
	tcgetattr(0, &g_sh.term);
	tcgetattr(0, &g_sh.backup);
	g_sh.term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &g_sh.term);
}

void	return_terminal(void)
{
	tcsetattr(0, TCSANOW, &g_sh.backup);
}
