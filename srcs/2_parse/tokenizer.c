/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:38:51 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:38:52 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_conf	g_sh;

static void	start(t_tool *tool, char *lex)
{
	if (lex[tool->i] == 'D' || lex[tool->i] == 'Q')
		tool->is_quote = 1;
	tool->st = tool->i;
}

static void	append_redir_or_hdoc(t_tool *tool)
{
	tool->i += 1;
	tool->ed = tool->st + 1;
	make_token(g_sh.token, tool->st, tool->ed);
	tool->st = -1;
	tool->ed = -1;
}

static void	redir_or_pipe_token(t_tool *tool)
{
	tool->ed = tool->i;
	make_token(g_sh.token, tool->st, tool->ed);
	tool->st = -1;
	tool->ed = -1;
}

static int	check_lex(t_tool *tool, char *lex)
{
	if (lex[tool->i + 1] == 's' || lex[tool->i + 1] == '\0')
		return (1);
	else if (ft_strchr("HIOAP", lex[tool->i + 1]))
		return (1);
	return (0);
}

int	tokenizer(char *lex)
{
	t_tool	tool;

	init_tool(&tool);
	while (lex[++(tool.i)])
	{
		if (tool.st == -1 && lex[tool.i] != 's')
			start(&tool, lex);
		if (tool.st >= 0 && ft_strchr("AH", lex[tool.st]))
			append_redir_or_hdoc(&tool);
		else if (tool.st >= 0 && ft_strchr("OIP", lex[tool.st]))
			redir_or_pipe_token(&tool);
		else if (tool.st >= 0)
		{
			if ((check_lex(&tool, lex)) == 1)
			{
				tool.ed = tool.i;
				make_token(g_sh.token, tool.st, tool.ed);
				tool.st = -1;
				tool.ed = -1;
				tool.is_quote = 0;
			}
		}
	}
	analyze_token(g_sh.token);
	return (analyze_syntax(g_sh.token));
}
