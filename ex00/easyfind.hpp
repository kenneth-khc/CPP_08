/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 01:09:34 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/11 05:14:58 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator	easyfind(T& container, int num)
{
	return std::find(container.begin(), container.end(), num);
}

#if 0 // Manual iteration
template<typename T>
typename T::iterator	easyfind(T& container, int num)
{
	typename T::iterator	begin = container.begin();
	typename T::iterator	end = container.end();

	for (typename T::iterator curr = begin; curr != end; ++curr)
	{
		if (*curr == num)
		{
			return curr;
		}
	}
	return end;
}
#endif

#endif
