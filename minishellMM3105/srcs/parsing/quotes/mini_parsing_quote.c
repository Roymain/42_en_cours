/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parsing_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:30:46 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/30 17:14:42 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*mini_join_arg(char *str, t_mini *mini, int *stri, char *tmp)
{
	char	*arg;
	int		j;

	arg = ft_track(malloc(ft_strlen(str) + 1 * sizeof(char)), mini->track_cmd);
	j = 0;
	while (str[*stri] && str[*stri] != ' ')
	{
		arg[j] = str[*stri];
		j++;
		*stri += 1;
	}
	arg[j] = 0;
	tmp = mini_strjoin(tmp, mini_return(arg, mini->env));
	*stri = ft_strlen(tmp) - 1;
	tmp = ft_strjoin(tmp, str + *stri + ft_strlen(arg));
	return (tmp);
}

static int	mini_condition(char **str, int i, t_mini *mini)
{
	if ((*str[i - 1] == '<' && *str[i - 2] == '<')
		|| (*str[i - 2] == '<' && *str[i - 3]))
	{
		*str[i] = ' ';
		i++;
		while (*str[i] != '"')
		{
			if (*str[i] == ' ')
				*str[i] = '\\';
			i++;
		}
		*str[i] = ' ';
	}
	else
		*str = ft_double(*str, mini, &i);
	return (i);
}

static char	*mini_init_quotes(int *j, int *i, char *q, t_mini *mini)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_track(malloc((100 + 3) * sizeof(char)), mini->track_cmd);
	*q = 'q';
	*i = 0;
	*j = 0;
	return (tmp);
}

static void	mini_display_quote(const int *start, const int *stop,
	char *tmp, const char *str)
{
	int	i;
	int	j;

	i = *stop;
	j = *start;
	while (j < i)
	{
		tmp[j] = str[j];
		j++;
	}
	tmp[j] = 0;
}

char	*ft_quotes(char *str, t_mini *mini)
{
	char	*tmp;
	int		i;
	int		j;
	char	q;

	tmp = mini_init_quotes(&j, &i, &q, mini);
	while (str[i] && str[i + 1])
	{
		if (str[i] == '\'' || str[i] == '"' || str[i] == '$')
		{
			q = str[i];
			if (q == '\'')
				str = ft_simple(str, &i, mini->track_cmd);
			else if (q == '"')
				i = mini_condition(&str, i, mini);
			else if (q == '$')
			{
				mini_display_quote(&j, &i, tmp, str);
				str = mini_join_arg(str, mini, &i, tmp);
			}
		}
		q = 'q';
		i++;
	}
	return (str);
}
