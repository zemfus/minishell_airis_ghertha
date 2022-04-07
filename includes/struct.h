/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:16:56 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:16:57 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <termios.h>
# include <unistd.h>

typedef struct s_status
{
	int					hdoc;
	int					input;
	int					output;
	int					result;
}	t_status;

typedef struct s_lst
{
	void				*head;
	void				*tail;
}	t_lst;

typedef struct s_lexer
{
	char				*lex;
	int					s_quote;
	int					e_quote;
	int					is_quote;
	int					err;
}	t_lexer;

typedef struct s_token
{
	char				*token;
	char				type;
	int					syntax;
	int					i;
	int					st;
	int					ed;
	struct s_token		*next;
	struct s_token		*prev;
}	t_token;

typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
	struct s_env		*prev;
}	t_env;

typedef struct s_redirect
{
	char				type;
	char				*arg;
	int					fd;
	struct s_redirect	*next;
	struct s_redirect	*prev;
}	t_redirect;

typedef struct s_cmd
{
	int					i;
	char				*cmd;
	char				*bin;
	char				*arg;
	char				**args;
	int					input_fd;
	int					output_fd;
	char				*input_redir;
	char				*output_redir;
	int					append;
	char				dir[2048];
}	t_cmd;

typedef struct s_tool
{
	int					i;
	int					is_quote;
	int					st;
	int					ed;
	int					pipe;
	int					redir;
	int					a_redir;
	int					heredoc;
}	t_tool;

typedef struct s_blt
{
	char				*p_cmd;
	int					opt;
	int					up_flag;
	char				*args;
}	t_blt;

typedef struct s_pipe
{
	int					fd[2];
	pid_t				*pid;
	t_env				env;
}	t_pipe;

typedef struct s_control
{
	t_lst				*redir;
	t_lst				*i_redir;
	t_lst				*o_redir;
}	t_control;

typedef struct s_process
{
	int					i;
	t_cmd				*cmd;
	t_control			*con;
	int					redir_err;
	struct s_process	*next;
	struct s_process	*prev;
}	t_process;

typedef struct s_conf
{
	char				*cmd;
	char				**envp;
	int					fd_backup[2];
	int					exit_status;
	t_lst				*env;
	t_lexer				*lexer;
	t_lst				*token;
	t_lst				*process;
	struct termios		term;
	struct termios		backup;
	int					col;
	t_pipe				pipe;
}	t_conf;

#endif
