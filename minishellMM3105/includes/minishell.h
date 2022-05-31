/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:41 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/30 18:01:20 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>

# include "../libft/includes/libft.h"
# include "mini_struct.h"
# include "mini_builtin.h"
# include "mini_exec.h"
# include "parsing/mini_parsing.h"
# include "../srcs/utils/tracker/include/tracker.h"

char	*ft_nobackpossiblee(char *str);
void	ft_nobackpossible(char **str);

char	*ft_strjoinequal(char const *s1, char const *s2);
char	**ft_trad(t_env *env);
int		ft_lstsize_env(t_list *lst);

char	*ft_catpath(char	*cmd, char *dir);
char	*ft_path(char *cmd, char **env, int i);

int		contentequal(char *str, char c);
void	mini_quit(int num);
void	mini_handler(int num);

#endif
