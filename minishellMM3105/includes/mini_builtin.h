/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_builtin.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:41:43 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/30 17:43:27 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_BUILTIN_H
# define MINI_BUILTIN_H

# include <stdio.h>
# include "mini_struct.h"

void	builtin_env(t_env *env);
void	builtin_pwd(void);
void	builtin_unset(t_env *env, char *key);
void	builtin_echo(char *str);
void	builtin_export(t_env *env, char *export);
void	builtin_cd(t_env *env, char *dir);

#endif
