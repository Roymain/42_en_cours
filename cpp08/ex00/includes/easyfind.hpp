/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:00:13 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/10 00:03:57 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T &truc, const int entier)
{
    return (std::find(truc.begin(), truc.end(), entier));
}
            
