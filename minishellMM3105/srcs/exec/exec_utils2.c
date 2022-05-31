/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 05:22:37 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/31 03:15:06 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		{
			if (ft_strncmp((*lst)->redir->key, "<<",
					ft_strlen((*lst)->redir->key)) == 0)
				i++;
		}
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

void	ft_creationheredoc(t_list **lst)
{
	char	*line;
	int		fd;

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
}

void	ft_prepheredoc(t_list **lst)
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
				ft_creationheredoc(lst);
			(*lst)->redir = (*lst)->redir->next;
		}
		(*lst)->redir = tmp2;
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
}
