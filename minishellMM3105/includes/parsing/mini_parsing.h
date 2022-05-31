/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parsing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:27:08 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/31 04:44:17 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PARSING_H
# define MINI_PARSING_H

# include "mini_struct.h"

char	*ft_quotes(char *str, t_mini *mini);
void	ft_parsenv(t_list **list, char **ev, t_track **t);
char	*ft_simple(char *str, int *i, t_track *tracker);
char	*ft_double(char *str, t_mini *mini, int *i);
void	mini_parsing_line(char *line, t_mini *mini);

void	ft_parse_redir(t_list *list, t_mini *mini);
int		mini_redirection_first_part(char **cmd, t_mini *mini, int i);
void	mini_do_loop(char **cmd, int j, t_mini *mini, t_list *list);
/* Utils */

char	*mini_strjoin(char *s1, char const *s2);
char	*mini_return(char *arg, t_env *env);
int		**mini_push_int_tab(int *a, int *b);

#endif
