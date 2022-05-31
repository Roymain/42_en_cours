/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:46:07 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/31 04:43:16 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_EXEC_H
# define MINI_EXEC_H

# include "mini_struct.h"

void	ft_exec(t_mini *mini, t_list *tmp);
void	ft_redir(t_list *lst, t_list *cmd);
int		ft_isitbuiltin(char *str);
void	ft_execbuiltin(t_list *cmd, pid_t pid, t_env *env);
void	ft_execbuiltinpipe(t_list *cmd, int	*pfd, t_env *ennv);
void	ft_execbuiltinn(t_list *cmd, int *pfd, t_cmd *s, t_env *ennv);
void	ft_usebuiltin(char *str, t_env *env);
int		ft_checkifredir(t_list **lst);
void	ft_prepheredoc(t_list **lst);
void	ft_unlink(t_list **lst);

#endif
