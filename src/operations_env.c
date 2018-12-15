/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:17:00 by oriabyi           #+#    #+#             */
/*   Updated: 2018/05/02 13:17:00 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		get_env(char **m_env)
{
	size_t	temp;
	t_env	*temp_env;

	g_env = (t_env *)malloc(sizeof(t_env));
	temp_env = g_env;
	while (*m_env)
	{
		temp = lenght_to_char(*m_env, '=');
		g_env->key = ft_strsub(*m_env, 0, temp);
		g_env->value = ft_strsub(*m_env, (temp + 1), ft_strlen(*m_env) - temp);
		if (++m_env && *m_env)
		{
			g_env->next = (t_env *)malloc(sizeof(t_env));
			g_env = g_env->next;
		}
		else
			g_env->next = NULL;
	}
	g_env = temp_env;
}

int			set_env(char *key, char *value)
{
	t_env	*root_env;

	root_env = g_env;
	while (root_env && root_env->next &&
			root_env->key && ft_strcmp(root_env->key, key))
		root_env = root_env->next;
	if (root_env && (root_env->next ||
			(root_env->key && !ft_strcmp(root_env->key, key))))
	{
		if (!root_env->key)
			root_env->key = ft_strdup(key);
		free(root_env->value);
		root_env->value = ft_strdup(value);
	}
	else
	{
		root_env->next = (t_env *)malloc(sizeof(t_env));
		root_env = root_env->next;
		root_env->key = ft_strdup(key);
		root_env->value = ft_strdup(value);
		root_env->next = NULL;
	}
	return (1);
}

int			unset_env(char *key)
{
	t_env	*list;
	t_env	*parent;
	t_env	*tmp;

	list = g_env;
	parent = NULL;
	while (list && list->key)
	{
		tmp = list;
		if (!ft_strcmp(list->key, key))
		{
			if (parent)
				parent->next = list->next;
			else
				list = list->next;
			free(list->key);
			free(list->value);
			free(list);
			break ;
		}
		else
			parent = list;
		list = tmp->next;
	}
	return (1);
}

char		**listtomatrix(void)
{
	char	**ret;
	t_env	*temp;
	char	**dest;
	int		i;

	i = 0;
	temp = g_env;
	while (temp && ++i)
		temp = temp->next;
	ret = (char **)malloc(sizeof(char *) * (i + 1));
	dest = ret;
	while (g_env && g_env->key)
	{
		*ret = ft_multjoin(3, g_env->key, "=", g_env->value);
		ret++;
		g_env = g_env->next;
	}
	return (dest);
}

char		*get_value_env(char *key)
{
	t_env	*root;

	root = g_env;
	while (root && root->key)
	{
		if (!ft_strcmp(root->key, key))
			return (ft_strdup(root->value));
		root = root->next;
	}
	return (NULL);
}
