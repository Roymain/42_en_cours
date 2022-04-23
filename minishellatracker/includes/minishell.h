/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:41 by rcuminal          #+#    #+#             */
/*   Updated: 2022/04/22 23:11:38 by rcuminal         ###   ########.fr       */
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
	int				fdin;
	int				fdout;
	t_list	*listcmd;						//$ truc
}			t_cmd;



char	*ft_nobackpossiblee(char *str);
void	ft_nobackpossible(char **str);

char	*ft_strjoinequal(char const *s1, char const *s2);
char	**ft_trad(t_env *env);
int		ft_lstsize_env(t_list *lst);

char	*ft_catpath(char	*cmd, char *dir);
char	*ft_path(char *cmd, char **env, int i);
int		ft_exec(t_env *env, t_cmd *cmd);

void	ft_parsenv(t_list **list, char **ev, t_track **t);
void	parsingline(char *line, t_cmd	*cmd, t_track *track, t_env *env);

void	builtin_export(t_env *env, char *export);
void	builtin_env(t_env *env);
void	builtin_cd(t_env *env, char *dir);
void	builtin_pwd();
void	builtin_unset(t_env *env, char *key);

int		contentequal(char *str, char c);
int		ft_compare(char *prev, char *next);

#endif
