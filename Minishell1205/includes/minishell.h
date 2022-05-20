/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:41 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/20 05:15:50 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include "../tracker/tracker.h"

typedef struct	s_sig
{
    int     si_signo;       /* Numéro de signal         */
    int     si_errno;       /* Numéro d'erreur          */
    int     si_code;        /* Code du signal           */
    pid_t   si_pid;         /* PID de l'émetteur        */
    uid_t   si_uid;         /* UID réel de l'émetteur   */
    int     si_status;      /* Valeur de sortie         */
    clock_t si_utime;       /* Temps utilisateur écoulé */
    clock_t si_stime;       /* Temps système écoulé     */
    int     si_int;         /* Signal POSIX.1b          */
    void   *si_ptr;         /* Signal POSIX.1b          */
    void   *si_addr;        /* Emplacement d'erreur     */
    int     si_band;        /* Band event               */
    int     si_fd;          /* Descripteur de fichier   */
}			t_siginfo;

typedef struct s_env
{
	t_list	*list;
}			t_env;

typedef struct s_cmd
{
	int				fdin;
	int				fdout;
	int				dernierfork;
	int				status;
	t_list			*listcmd;
}			t_cmd;

void	ft_redir(t_list *lst, t_list *cmd);
int		ft_checkifredir(t_list **lst);

char	*ft_pathuser(t_env *env, char *dir);
void	ft_prepheredoc(t_list **lst, t_cmd *cmd);
void	ft_unlink(t_list **lst);

void	builtin_export(t_env *env, char *export);
void	builtin_env(t_env *env);
void	builtin_cd(t_env *env, char *dir);
void	builtin_pwd(void);
void	builtin_unset(t_env *env, char *key);
void	builtin_echo(char *str);
int		ft_optionecho(char *str);

void	ft_execbuiltin(t_list *cmd, pid_t pid, int	*pfd, t_env *env);
void	ft_execbuiltinpipe(t_list *cmd, int	*pfd, t_env *ennv);
void	ft_execbuiltinn(t_list *cmd, int	*pfd, t_cmd *s, t_env *ennv);
void	ft_usebuiltin(char *str, t_env *env);
int		ft_isitbuiltin(char *str);

char	*ft_catpath(char	*cmd, char *dir);
char	*ft_path(char *cmd, char **env, int i);
void	ft_exec(t_env *env, t_cmd *cmd, t_list *tmp);

void	ft_parsenv(t_list **list, char **ev, t_track **t);
void	parsingline(char *line, t_cmd	*cmd, t_track *track, t_env *env);

char	**ft_trad(t_env *env);
char	*ft_strjoinequal(char const *s1, char const *s2);
char	*ft_nobackpossiblee(char *str);
void	ft_nobackpossible(char **str);
int		already_in(t_list	*list, char *key);
void	export_modif(t_list *list, char *content);
int		ft_lstsize_env(t_list *lst);
int		contentequal(char *str, char c);
int		ft_compare(char *prev, char *next);

#endif
