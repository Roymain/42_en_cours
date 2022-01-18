/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:19:38 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/18 02:31:37 by rcuminal         ###   ########.fr       */
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
	int		sleep;
	int		pfd[2];
	int		fd1;
	int		fd2;
	int		i;
	char	*fn;
	char	*bin;
	char	*path;
	t_list	*list;
}			t_val;

void	ft_lstprint(t_list *lst);
int		ft_parsargv(char **argv, t_list **list, int argc, int i);

#endif