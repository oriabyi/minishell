/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:44:00 by oriabyi           #+#    #+#             */
/*   Updated: 2018/05/02 12:44:00 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t		lenght_to_char(char *word, char c)
{
	size_t	i;

	i = 0;
	if (word)
		while (*word)
		{
			if (*word == c)
				break ;
			i++;
			word++;
		}
	return (i);
}

int			print_char_l(void)
{
	t_env	*temp;

	temp = g_env;
	while (temp && temp->key)
	{
		ft_putstr(temp->key);
		ft_putchar('=');
		ft_putendl(temp->value);
		temp = temp->next;
	}
	return (1);
}

int			free_matrix(char **s)
{
	int		i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		free(s[i++]);
	}
	free(s);
	return (1);
}

void		print_prompt(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 1024);
	ft_putstr("\033[36m");
	ft_putstr(pwd);
	free(pwd);
	ft_putstr(": \033[0m");
}
