/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_content_equal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:58:46 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/17 09:59:17 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_builtin.h"

int	mini_content_equal(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
