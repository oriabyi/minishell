/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 11:34:00 by oriabyi           #+#    #+#             */
/*   Updated: 2018/05/03 11:34:00 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			if_dollar(char **command, int *bui_i, int *bui_j)
{
	char		*temp_value_env;
	char		buff[32];
	int			p;
	int			i;
	int			j;

	p = 0;
	i = *bui_i;
	j = *bui_j;
	j++;
	ft_bzero(buff, 32);
	while (command[i][j] && command[i][j] != ' ' && command[i][j] != '\t')
		buff[p++] = command[i][j++];
	temp_value_env = get_value_env(buff);
	ft_putstr(temp_value_env);
	free(temp_value_env);
	ft_bzero(buff, 32);
	*bui_i = i;
	*bui_j = j;
}

int				builtin_echo(char **command)
{
	int			i;
	int			j;

	i = 0;
	while (command[i] || !ft_putchar('\n'))
	{
		j = 0;
		while (command[i][j] || !ft_putchar(' '))
		{
			if (command[i][j] == '$')
				if_dollar(command, &i, &j);
			if (command[i][j] && command[i][j] != '\'' && command[i][j] != '\"')
				ft_putchar(command[i][j]);
			j++;
		}
		i++;
	}
	return (1);
}
