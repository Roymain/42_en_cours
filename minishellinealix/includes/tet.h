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

shell = ft_bzero(shell, sizeof(t_shell));
tracker = ft_memalloc(sizeof(t_track));

typedef struct s_env
{
	t_list	*list;
}			t_env;

typedef struct s_cmd
{
	t_list	*listcmd;						//$ truc
}			t_cmd;

typedef struct s_shell
{
	t_track *tracker;
}			t_shell;


void	builtin_cd(t_env *env, char *dir, char *path);
void	builtin_pwd(char *path);
void	builtin_unset(t_env *env, char *key);

#endif