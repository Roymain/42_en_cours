/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:25:19 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/11 22:25:20 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	if (!argv[1])
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (isalpha(argv[j][i]) == 1)
				argv[j][i] = toupper(argv[j][i]);
			i++;
		}
		i = 0;
		j++;
	}
	i++;
	while (argv[i])
	{
		std::cout << argv[i];
		i++;
	}
	std::cout << std::endl;
	return (0);
}