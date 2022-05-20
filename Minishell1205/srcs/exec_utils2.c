/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 05:22:37 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/12 23:51:58 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_nobackpossiblee(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			str[i] = ' ';
		i++;
	}
	return (str);
}

void	ft_nobackpossible(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '\\')
				str[i][j] = ' ';
			j++;
		}
		i++;
	}
}

int	ft_checkifredir(t_list **lst)
{
	t_list		*tmp;
	int			i;

	i = 0;
	tmp = (*lst);
	while ((*lst))
	{
		if ((*lst)->redir)
			i++;
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
	return (i);
}

void	ft_unlink(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*lst);
	while ((*lst))
	{
		while ((*lst)->redir)
		{
			tmp2 = (*lst)->redir;
			if (ft_strncmp((*lst)->redir->key, "<< ",
					ft_strlen((*lst)->redir->key)) == 0)
				unlink((*lst)->redir->content);
			(*lst)->redir = (*lst)->redir->next;
		}
		(*lst)->redir = tmp2;
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
}

void ft_prepheredoc(t_list **lst, t_cmd *cmd)
{
	char	*line;
	int		fd;
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*lst);
	while ((*lst))
	{
		while ((*lst)->redir)
		{
			tmp2 = (*lst)->redir;
			if (ft_strncmp((*lst)->redir->key, "<< ",
					ft_strlen((*lst)->redir->key)) == 0)
			{
				fd = open((*lst)->redir->content,
						O_RDWR | O_CREAT | O_APPEND, 0777);
				line = readline("> ");
				while (ft_strncmp(line, (*lst)->redir->content,
						ft_strlen((*lst)->redir->content)) != 0
					&& line)
				{
					ft_putstr_fd(line, fd);
					free(line);
					line = readline("> ");
				}
				free(line);
				// dup2(cmd->fdout, 1);
				// dup2(cmd->fdin, 0);
			}
			(*lst)->redir = (*lst)->redir->next;
		}
		(*lst)->redir = tmp2;
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
}
