/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:38:09 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:38:10 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_conf	g_sh;

void	mark_token_type(t_token *tmp, char type, int *find_cmd)
{
	tmp->type = type;
	if (type == 'C')
		*find_cmd = 1;
}

int	check_unexpected_token(t_token *node)
{
	if (node->next == NULL)
	{
		if (node->type == 'P')
			return (2);
		token_error("newline", ERRNO_UNEXPECTED_TOKEN);
		return (-1);
	}
	else if (node->next != NULL)
	{
		if (ft_strchr("AFHIOP", node->next->type))
		{
			if (node->type == 'P' && ft_strchr("FHIOA", node->next->type))
				return (1);
			token_error(node->next->token, ERRNO_UNEXPECTED_TOKEN);
			return (-1);
		}
	}
	return (1);
}

int	check_token_type(t_lst *token, t_token *tmp, int find)
{
	if (tmp == token->head)
		return (1);
	else if (find == 0 && (tmp->prev != 0 && ft_strchr("TD", tmp->prev->type)))
		return (1);
	else if (tmp->i == 0 && find == 0)
		return (1);
	else if (tmp->prev != NULL && ft_strchr("IOA", tmp->prev->type))
		return (2);
	else if (tmp->prev != NULL && tmp->prev->type == 'H')
		return (3);
	return (0);
}

int	analyze_unexpected_token(t_token *tok)
{
	t_token	*tmp;
	int		ret;

	ret = 0;
	tmp = tok;
	while (tmp)
	{
		if (ft_strchr("AOIPH", tmp->type))
			ret = check_unexpected_token(tmp);
		if (ret == -1 || ret == 2)
			return (ret);
		tmp = tmp->next;
	}
	return (ret);
}

int	analyze_syntax(t_lst *token)
{
	t_token	*tmp;
	int		find_cmd;
	int		ret;

	find_cmd = 0;
	tmp = token->head;
	ret = analyze_unexpected_token(tmp);
	if (ret == -1 || ret == 2)
		return (ret);
	while (tmp)
	{
		if (tmp->type == 'S')
		{
			if ((check_token_type(token, tmp, find_cmd)) == 1)
				mark_token_type(tmp, 'C', &find_cmd);
			else if ((check_token_type(token, tmp, find_cmd)) == 2)
				mark_token_type(tmp, 'T', &find_cmd);
			else if ((check_token_type(token, tmp, find_cmd)) == 3)
				mark_token_type(tmp, 'D', &find_cmd);
		}
		else if (tmp->type == 'P')
			find_cmd = 0;
		tmp = tmp->next;
	}
	return (ret);
}
