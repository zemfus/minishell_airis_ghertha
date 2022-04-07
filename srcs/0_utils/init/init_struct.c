/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:32:12 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:32:13 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern t_conf	g_sh;

void	init_cmd(t_cmd *node)
{
	node->arg = NULL;
	node->args = NULL;
	node->cmd = NULL;
	node->append = 0;
	node->input_fd = -1;
	node->output_fd = -1;
	node->bin = NULL;
	node->input_redir = NULL;
	node->output_redir = NULL;
}

void	init_config(void)
{
	g_sh.lexer = NULL;
	g_sh.process = malloc(sizeof(t_lst));
	g_sh.token = malloc(sizeof(t_lst));
	init_lst(g_sh.process);
	init_lst(g_sh.token);
}

void	init_lexer(t_lexer *lexer)
{
	lexer->is_quote = 0;
	lexer->s_quote = 0;
	lexer->e_quote = 0;
	lexer->err = 0;
	lexer->lex = NULL;
}

void	init_lst(t_lst *lst)
{
	lst->head = NULL;
	lst->tail = NULL;
}

void	init_control(t_control *con)
{
	con->redir = malloc(sizeof(t_lst));
	con->o_redir = malloc(sizeof(t_lst));
	con->i_redir = malloc(sizeof(t_lst));
	init_lst(con->redir);
	init_lst(con->o_redir);
	init_lst(con->i_redir);
}
