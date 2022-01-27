/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:get_next_line/get_next_line_bonus.h
/*   Created: 2021/11/15 13:08:03 by rcuminal          #+#    #+#             */
/*   Updated: 2021/11/18 04:14:40 by rcuminal         ###   ########.fr       */
=======
/*   Created: 2022/01/04 21:19:38 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/19 18:27:34 by Romain           ###   ########.fr       */
>>>>>>> 99685bb2725f3bdad439ff611718074a0630efa9:pipex_finito/includes_bonus/pipex_bonus.h
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
<<<<<<< HEAD:get_next_line/get_next_line_bonus.h
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
=======
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

>>>>>>> 99685bb2725f3bdad439ff611718074a0630efa9:pipex_finito/includes_bonus/pipex_bonus.h

int		ft_strlen(char *theString);
char	*get_next_line(int fd);
void	*ft_calloc( size_t elementCount, size_t elementSize);
char	*ft_replace(char *buffer, int i);
int		ft_checkn(char *buffer, char c);
char	*ft_realloc(char *strr, int i, char *buffer);
#endif