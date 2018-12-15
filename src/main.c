/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:09:56 by oriabyi           #+#    #+#             */
/*   Updated: 2018/05/07 20:09:57 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				is_builtin(char **command)
{
	if (!ft_strcmp(command[0], "env"))
		return (print_char_l());
	else if (!ft_strcmp(command[0], "setenv"))
		return (set_env(command[1], command[2]));
	else if (!ft_strcmp(command[0], "unsetenv"))
		return (unset_env(command[1]));
	else if (!ft_strcmp(command[0], "cd"))
		return (builtin_cd(command));
	else if (!ft_strcmp(command[0], "echo"))
		return (builtin_echo(command + 1));
	else if (!ft_strcmp(command[0], "exit"))
		return (-1);
	else if (!ft_strcmp(command[0], "clear"))
		return (system("clear"));
	return (0);
}

int				last_check(char **command, char *temp, char **to_free)
{
	struct stat	sb;
	pid_t		child_pid;

	if (lstat(temp, &sb) != -1)
	{
		signal(SIGINT, proc_s_check);
		if (access(temp, X_OK) == -1)
			return (er_access(temp, to_free));
		child_pid = fork();
		if (!child_pid)
		{
			execve(temp, command, listtomatrix());
			free(temp);
			exit(0);
		}
		else
			free(temp);
		waitpid(child_pid, 0, WUNTRACED);
		free_matrix(to_free);
		return (1);
	}
	else
		free(temp);
	return (0);
}

int				is_env(char **com)
{
	char		**to_free_matrix_path;
	char		**m_path;
	char		*temp;
	int			verdict;
	int			i;

	i = 1;
	temp = get_value_env("PATH");
	m_path = ft_strsplit(temp, ':', 0);
	free(temp);
	to_free_matrix_path = m_path;
	while ((m_path && *m_path) || ((com[0][0] == '/') && i))
	{
		if (com[0][0] != '/' && com[0][0] != '.')
			temp = ft_multjoin(3, *m_path, "/", com[0]);
		else
			temp = ft_strdup(com[0]);
		if ((verdict = last_check(com, temp, to_free_matrix_path)) != 0)
			return (verdict);
		m_path++;
		i = 0;
	}
	free_matrix(to_free_matrix_path);
	return (0);
}

void			carry_out(char *line)
{
	char		**to_free_semi_commands;
	char		**semi_commands;
	char		**command;
	int			verdict;

	verdict = 0;
	if (!(semi_commands = ft_strsplit(line, ';', 0)) || !*semi_commands)
		return ;
	to_free_semi_commands = semi_commands;
	while (*semi_commands)
	{
		if (!(command = ft_strsplit(*semi_commands, ' ', 1)) || !*command)
			return ;
		tilde_swap(&command);
		if (!(verdict = is_builtin(command)))
			if (!is_env(command) && ft_putstr("minishell: command not found: "))
				ft_putendl_ascii(command[0]);
		free_matrix(command);
		if (verdict == -1)
			break ;
		semi_commands++;
	}
	free_matrix(to_free_semi_commands);
	if (verdict == -1 && ft_putstr("The minishell was closed.\n"))
		exit(0);
}

int				main(int ac, char **av, char **env)
{
	char		*input;

	(void)(**av | ac);
	get_env(env);
	while (ac)
	{
		signal(SIGINT, s_check);
		print_prompt();
		gnl(0, &input);
		carry_out(input);
		free(input);
	}
	return (0);
}
