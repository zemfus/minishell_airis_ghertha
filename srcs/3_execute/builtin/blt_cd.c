/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blt_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airis <airis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:39:07 by airis             #+#    #+#             */
/*   Updated: 2022/04/07 04:39:08 by airis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern t_conf	g_sh;

int	is_chdir(int ret, char *abs_pwd)
{
	if (ret == -1)
	{
		g_sh.exit_status = 1;
		if (abs_pwd)
			free(abs_pwd);
		return (1);
	}
	return (0);
}

void	check_error(int ret, char **b_args, char *abs_pwd)
{
	if (ret == -1)
	{
		if (abs_pwd == NULL)
			cd_error(*b_args, strerror(errno));
		else if (abs_pwd)
			cd_error(abs_pwd, strerror(errno));
	}
}

void	relative_path(char **b_args, char buf[512])
{
	int		ret;
	char	*home_pwd;
	char	*abs_pwd;

	abs_pwd = NULL;
	if (b_args[0][0] == '~' && b_args[0][1] == '/')
	{
		home_pwd = search_env_value("HOME", g_sh.env);
		abs_pwd = ft_strdup(home_pwd);
		abs_pwd = ft_strjoin(abs_pwd, (*b_args + 1));
	}
	if (abs_pwd == 0)
		ret = chdir(*b_args);
	else
		ret = chdir(abs_pwd);
	check_error(ret, b_args, abs_pwd);
	if (is_chdir(ret, abs_pwd))
		return ;
	else if (!(ret))
		getcwd(buf, 512);
	change_env_value("PWD", buf, g_sh.env);
	if (abs_pwd)
		free(abs_pwd);
}

void	run_cd(char *b_args, t_blt *blt)
{
	int		ret;
	char	buf[512];
	t_env	*home;

	if (blt->up_flag == 1)
		return ;
	change_env_lst("PWD", "OLDPWD", g_sh.env);
	if (!(b_args) || (ft_strcmp("~", b_args)) == 0)
	{
		change_env_lst("HOME", "PWD", g_sh.env);
		home = search_env_node("HOME", g_sh.env);
		ret = chdir(home->value);
		if (ret == -1)
		{
			return ;
			printf("here\n");
		}
		getcwd(buf, 512);
		change_env_value("PWD", buf, g_sh.env);
	}
	else
		relative_path(&b_args, buf);
}
