/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:38:26 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:38:27 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_conf	g_sh;

t_lexer	*lexer(char *cmd)
{
	int		i;
	t_lexer	*lexer;

	if (!cmd)
		return (NULL);
	lexer = malloc(sizeof(t_lexer));
	init_lexer(lexer);
	lexer->lex = ft_strdup(cmd);
	ft_memset(lexer->lex, 0, ft_strlen(cmd));
	i = -1;
	while (cmd[++i])
		analyze_lexicon(lexer, cmd, &i);
	if (lexer->s_quote != 0)
		lexer->err = 1;
	return (lexer);
}
