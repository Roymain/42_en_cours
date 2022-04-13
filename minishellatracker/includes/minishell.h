/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:41 by rcuminal          #+#    #+#             */
/*   Updated: 2022/04/13 04:25:44 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>

typedef struct s_env
{
	t_list	*list;
}			t_env;

typedef struct s_cmd
{
	t_list	*listcmd;						//$ truc
}			t_cmd;


char	*ft_catpath(char	*cmd, char *dir);
char	*ft_path(char *cmd, char **env, int i);
void	ft_exec(t_env *env, t_cmd *cmd);

void	ft_parsenv(t_list **list, char **ev, t_track **t);
void	parsingline(char *line, t_cmd	*cmd, t_track *track, t_env *env);

void	builtin_export(t_env *env, char *export);
void	builtin_env(t_env *env);
void	builtin_cd(t_env *env, char *dir, char *path);
void	builtin_pwd(char *path);
void	builtin_unset(t_env *env, char *key);

int	contentequal(char *str, char c);
int	ft_compare(char *prev, char *next);

#endif
