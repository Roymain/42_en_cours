/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_display_redir_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:06:26 by mathismartini     #+#    #+#             */
/*   Updated: 2022/06/22 20:06:26 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parsing.h"

void	mini_display_redir_error(void)
{
	write(2, "minishell: syntax error near unexpected token newline'\n", 56);
}
