/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:37:28 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:37:29 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern t_conf	g_sh;

static void	init_pos(int *x, int *y)
{
	*x = 0;
	*y = 0;
}

static int	print_tc(int tc)
{
	write(0, &tc, 1);
	return (1);
}

int	get_cursor_pos(int *x, int *y)
{
	int		ret;
	int		flag;
	char	ch;

	flag = 0;
	init_pos(x, y);
	set_term_cursor();
	write(0, "\033[6n", 4);
	while (1)
	{
		ret = read(0, &ch, 1);
		if (!ret || ch == 'R')
			return (set_term_default(0));
		else if (ch == ';')
			flag = 1;
		else if ((ch >= '0' && ch <= '9') && flag == 0)
			*x = (*x * 10) + (ch - '0');
		else if ((ch >= '0' && ch <= '9') && flag == 1)
			*y = (*y * 10) + (ch - '0');
	}
	return (set_term_default(1));
}

void	move_cursor(char *msg, int col, int row)
{
	int		x;
	int		y;
	char	*cm;

	x = 0;
	y = 0;
	get_cursor_pos(&x, &y);
	tgetent(NULL, getenv("TERM"));
	cm = tgetstr("cm", NULL);
	tputs(tgoto(cm, y + col, x - row), 0, print_tc);
	if (msg)
		printf("%s", msg);
}
