<<<<<<< HEAD:fdf/libft/ft_memcmp.c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:52:03 by rcuminal          #+#    #+#             */
/*   Updated: 2021/11/09 08:52:03 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:36:55 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/19 03:09:53 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

int	ft_parsargv(char **argv, t_list **list, int argc, int i)
{
	t_list	*tmp;

	while (i < argc - 1)
	{
		tmp = ft_lstnew(ft_split(argv[i], ' ', 0));
		ft_lstadd_back(list, tmp);
		i++;
	}
	return (0);
}

int	ft_checkarg(char **argv, int argc)
{
	int	i;

	i = 2;
	while (i < argc - 2)
	{
		if (argv[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	ft_freefn(char *fn)
{
	unlink(fn);
	free(fn);
}

int	ft_preheredoc(t_val *val, char **argv, char **env, int i)
{
	ft_freefn(val->fn);
	if (!val->list->next)
	{
		ft_pipexalone(val, env, val->list->cmd, val->list->pid);
		waitpid(val->list->pid, NULL, 0);
		ft_lstclear(&(val->list), &free);
		free(val);
		return (0);
	}
	return (1);
}

char	*ft_here_doc(t_val *val, char **argv, int argc)
{
	char	*fn;
	char	*line;

	fn = ft_strdup(".here_doc");
	val->fd1 = open(fn, O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0644);
	val->fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	while (1)
	{
		write(1, "here_doc> ", 11);
		line = get_next_line(0);
		line[ft_strlen(line) - 1] = '\0';
		if (ft_strncmp(argv[2], line, ft_strlen(line)) == 0)
		{
			free(line);
			return (fn);
		}
		line[ft_strlen(line)] = '\n';
		ft_putstr_fd(line, val->fd1);
		free (line);
	}
}
>>>>>>> 99685bb2725f3bdad439ff611718074a0630efa9:pipex_finito/srcs_bonus/utils_bonus.c
