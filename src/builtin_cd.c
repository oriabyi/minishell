/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:14:00 by oriabyi           #+#    #+#             */
/*   Updated: 2018/05/02 17:14:00 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				builtin_cd_help(char **command, char *temp_oldpwd,
																char *temp_pwd)
{
	int			cmp;

	if (command[1])
		cmp = ft_strcmp(command[1], "-");
	else
		return (0);
	if (command[1] && cmp)
	{
		if (chdir(command[1]) == -1)
		{
			if (access(command[1], 0))
			{
				ft_print_word_endl("cd: no such file or directory: ",
																command[1]);
			}
			else
			{
				ft_print_word_endl("cd: permission denied: ", command[1]);
			}
		}
		else
			set_env("OLDPWD", temp_pwd);
	}
	else if (command[1])
	{
		ft_putendl(temp_oldpwd);
		chdir(temp_oldpwd);
		set_env("OLDPWD", temp_pwd);
	}
	return (1);
}

int				builtin_cd(char **command)
{
	char		*temp_pwd;
	char		*temp_oldpwd;
	char		*temp_home;
	char		*temp_getcwd;

	if (command[1] && command[2])
	{
		ft_print_word_endl("cd: string not in pwd: ", command[1]);
		return (0);
	}
	temp_pwd = get_value_env("PWD");
	temp_home = get_value_env("HOME");
	temp_oldpwd = get_value_env("OLDPWD");
	temp_getcwd = getcwd(NULL, 1024);
	if (!builtin_cd_help(command, temp_oldpwd, temp_getcwd))
	{
		set_env("OLDPWD", temp_getcwd);
		chdir(temp_home);
	}
	set_env("PWD", temp_getcwd);
	free(temp_getcwd);
	free(temp_pwd);
	free(temp_oldpwd);
	free(temp_home);
	return (1);
}
