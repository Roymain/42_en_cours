/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-inutils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:42:31 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/31 04:53:12 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstmapp(t_list *lst)
{
	t_list	*var;
	t_list	*add;

	add = NULL;
	while (lst)
	{
		var = ft_lstnew("", "");
		var->content = ft_strdup(lst->content);
		var->key = ft_strdup(lst->key);
		lst = lst->next;
		ft_lstadd_back(&add, var);
	}
	return (add);
}

void	ft_lstsortswap(void *save, void *savee, t_list *current)
{
	save = NULL;
	savee = NULL;
	save = current->content;
	savee = current->key;
	current->content = current->next->content;
	current->key = current->next->key;
	current->next->content = save;
	current->next->key = savee;
}

t_list	*ft_lstsort(t_list *begin_list, int i, int j, int size)
{
	t_list	*help;
	t_list	*current;
	void	*save;
	void	*savee;

	save = NULL;
	savee = NULL;
	size = ft_lstsize(begin_list);
	help = ft_lstmapp(begin_list);
	while (i < size)
	{
		j = 0;
		current = help;
		while (j < size - 1 - i)
		{
			if (current->key[0] > current->next->key[0])
				ft_lstsortswap(save, savee, current);
			current = current->next;
			j++;
		}
		i++;
	}
	return (current);
}

int	print_list(t_list *list)
{
	while (list)
	{
		printf("declare -x ");
		printf("%s=", list->key);
		printf("%s\n", list->content);
		list = list->next;
	}
	return (1);
}

void	ft_usebuiltin(char *str, t_env *env)
{
	t_list	*export;

	if (ft_strncmp(str, "unset ", 5) == 0)
		builtin_unset(env, str + 6);
	if (ft_strncmp(str, "export ", 7) == 0)
		return (builtin_export(env, str + 7));
	if (ft_strncmp(str, "export", 6) == 0)
	{
		export = ft_lstsort(env->list, 0, 0, 0);
		print_list(export);
	}
	if (ft_strncmp(str, "cd ", 3) == 0)
		builtin_cd(env, str + 3);
	if (ft_strncmp(str, "cd", ft_strlen(str)) == 0)
		builtin_cd(env, "/");
	if (ft_strncmp(str, "pwd", ft_strlen(str)) == 0)
		builtin_pwd();
	if (ft_strncmp(str, "env", ft_strlen(str)) == 0)
		builtin_env(env);
	if (ft_strncmp(str, "echo ", ft_strlen("echo ")) == 0)
		builtin_echo(str);
}

int	ft_isitbuiltin(char *str)
{
	if (ft_strncmp(str, "unset ", 6) == 0)
		return (1);
	if (ft_strncmp(str, "export ", 7) == 0)
		return (1);
	if (ft_strncmp(str, "export", 6) == 0)
		return (1);
	if (ft_strncmp(str, "cd ", 4) == 0)
		return (1);
	if (ft_strncmp(str, "cd", 2) == 0)
		return (1);
	if (ft_strncmp(str, "pwd", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "env", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "echo ", ft_strlen("echo ")) == 0)
		return (1);
	return (0);
}
