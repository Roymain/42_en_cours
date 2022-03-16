/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:41 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/16 03:22:43 by rcuminal         ###   ########.fr       */
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

void	builtin_cd(t_env *env, char *dir, char *path);
void	builtin_pwd(char *path);
void	builtin_unset(t_env *env, char *key);

#endif
