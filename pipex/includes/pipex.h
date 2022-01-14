/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:20:56 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/13 23:33:14 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_val
{
	pid_t	pid[2];
	int		pfd[2];
	int		fd1;
	int		fd2;
	char	**cmd1;
	char	**cmd2;
	char	*bin;
	char	*path;
}			t_val;

void	ft_free(t_val *val);
char	*ft_path(char *cmd, char **env, t_val *val);
void	ft_freealone(char **good, char **wrong, t_val *val);

char	*ft_catpath(char	*cmd, char *dir);

#endif