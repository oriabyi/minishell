/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:13:42 by oriabyi           #+#    #+#             */
/*   Updated: 2018/05/07 20:13:43 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include "sys/param.h"
# include <signal.h>
# include "sys/stat.h"

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

t_env				*g_env;

int					print_char_l(void);
void				get_env(char **m_env);
int					set_env(char *key, char *value);
char				*get_value_env(char *key);
int					unset_env(char *key);
int					builtin_cd(char **command);
int					builtin_echo(char **command);
size_t				lenght_to_char(char *word, char c);
char				**listtomatrix();
int					free_matrix(char **s);
void				tilde_swap(char ***command);
int					ft_putendl_ascii(char *s);
void				s_check(int sig);
void				print_prompt(void);
int					er_access(char *temp, char **to_free);
void				proc_s_check(int sig);
void				ft_print_word_endl(char *message, char *word);

#endif
