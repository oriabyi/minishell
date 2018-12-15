/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:11:01 by oriabyi           #+#    #+#             */
/*   Updated: 2018/05/07 20:11:02 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_putendl_ascii(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (!ft_isascii(s[i]))
			break ;
		write(1, &(s[i]), 1);
		i++;
	}
	write(1, "\n", 1);
	return (1);
}

void		tilde_swap(char ***command)
{
	char	**temp;
	char	*temp_value;
	char	*temp_rfstr;

	temp = *command;
	temp_value = get_value_env("HOME");
	while (*temp)
	{
		if (**temp == '~' && *(*temp + 1) != '~')
		{
			temp_rfstr = ft_rfstr("~", *temp, temp_value, 2);
			ft_strdel(temp);
			*temp = ft_strdup(temp_rfstr);
			free(temp_rfstr);
		}
		temp++;
	}
	free(temp_value);
}

void		s_check(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		print_prompt();
		signal(SIGINT, s_check);
	}
}

void		proc_s_check(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		signal(SIGINT, s_check);
	}
}

int			er_access(char *temp, char **to_free)
{
	ft_putstr("minishell: ");
	ft_putstr(temp);
	ft_putstr(": Permission denied\n");
	free_matrix(to_free);
	return (-1);
}

void		ft_print_word_endl(char *message, char *word)
{
	ft_putstr(message);
	ft_putendl(word);
}
