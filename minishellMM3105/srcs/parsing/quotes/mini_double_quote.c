/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_double_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:39:41 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/26 19:12:47 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*mini_arg_join(char *str, t_mini *mini, char *tmp, int *index[2])
{
	char	*arg;
	int		j;

	arg = malloc(ft_strlen(str) + 1 * sizeof(char));
	j = 0;
	*index[0] += 1;
	while (str[*index[1]] && str[*index[1]] != ' '
		&& str[*index[1]] != '"' && str[*index[1]] != '\'')
	{
		arg[j] = str[*index[1]];
		j++;
		*index[0] += 1;
		*index[1] += 1;
	}
	arg[j] = 0;
	tmp = mini_strjoin(tmp, mini_return(arg, mini->env));
	*index[0] = ft_strlen(tmp) - 1;
	tmp = mini_strjoin(tmp, str + *index[1] + 1);
	*index[1] -= 1;
	free(index);
	free(arg);
	return (tmp);
}

static int	mini_skip(const char *str, int *max_value, char *tmp)
{
	int	j;

	j = 0;
	while (str[j] && j < *max_value)
	{
			tmp[j] = str[j];
			j++;
	}
	*max_value += 1;
	return (j);
}

static char	*mini_in_double_quote(char *str, int *i, int *value, t_mini *mini)
{
	char	*tmp;
	int		j;

	tmp = ft_track(malloc(ft_strlen(str) + 1 * sizeof(char)), mini->track_cmd);
	j = mini_skip(str, i, tmp);
	while (str[*i] && str[*i] != '"')
	{
		if (str[*i] == '$')
		{
			*value = 1;
			tmp[j] = 0;
			tmp = mini_arg_join(str, mini, tmp, mini_push_int_tab(&j, i));
		}
		else
		{
			if (str[*i] == ' ')
				tmp[j] = '\\';
			else
				tmp[j] = str[*i];
		}
		j++;
		*i += 1;
	}
	*i = j;
	return (tmp);
}

char	*ft_double(char *str, t_mini *mini, int *i)
{
	char	*tmp;
	int		j;
	int		value;

	tmp = NULL;
	value = 0;
	tmp = mini_in_double_quote(str, i, &value, mini);
	j = *i;
	if (value == 0)
	{
		tmp[j] = 0;
		tmp = mini_strjoin(tmp, str + *i + 2);
	}
	return (tmp);
}
