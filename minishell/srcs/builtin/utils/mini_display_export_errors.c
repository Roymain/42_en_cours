/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_display_builtin_errors.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:06:12 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/17 11:18:29 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_builtin.h"

void	mini_display_export_error(int error)
{
	if (error == NOT_VALID)
		write(2, "minishell: export: '=': not a valid identifier\n", 48);
}
