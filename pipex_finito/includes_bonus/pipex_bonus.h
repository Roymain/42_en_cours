/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:19:38 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/19 18:27:34 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/includes/libft.h"
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_val
{
	pid_t	pid;
	int		pfd[2];
	int		fd1;
	int		fd2;
	int		i;
	char	*fn;
	char	*bin;
	char	*path;
	t_list	*list;
}			t_val;

void	ft_pipexalone(t_val *val, char **env, char **cmd, pid_t pid);
void	ft_pipex(t_val *val, char **env, int fd, pid_t pid);

int		ft_parsargv(char **argv, t_list **list, int argc, int i);
int		ft_checkarg(char **argv, int argc);

int		ft_preheredoc(t_val *val, char **argv, char **env, int i);
char	*ft_here_doc(t_val *val, char **argv, int argc);

char	*ft_catpath(char	*cmd, char *dir);
char	*ft_path(char *cmd, char **env, t_val *val);

void	ft_waitallpid(t_list *lst);
void	ft_freefn(char *fn);
void	ft_redir(t_val *val);


#endif