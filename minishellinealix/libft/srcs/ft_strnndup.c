/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:16:18 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/03 00:57:46 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnndup(const char *src, int size, int start)
{
	int		i;
	char	*str;

	i = start;
	str = (char *)malloc((sizeof(char) * size) + 2);
	if (str == NULL)
		return (0);
	if (!src[i])
	{
		i = 0;
		str[i] = ' ';
		i++;
	}
	while (src[i])
	{
		str[i - start] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}