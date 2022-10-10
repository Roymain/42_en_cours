/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:49:43 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/09 22:57:54 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void    swap(T &un, T &deux){
    T tmp = deux;
    deux = un;
    un = tmp;
}

template <typename T>
const T   &min(const T &un, const T &deux){
    if (un < deux)
        return (un);
    else
        return (deux);
}

template <typename T>
const T   &max(const T &un, const T &deux){
    if (un > deux)
        return (un);
    else
        return (deux);
}