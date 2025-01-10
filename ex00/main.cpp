/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 01:09:25 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/11 05:12:51 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include "easyfind.hpp"

template<typename Type>
void	println(const Type& t)
{
	std::cout << t << '\n';
}

template<typename ContainerType>
void	test()
{
	int	intArray[] = {1, 2, 3, 5, 6, 5, 42, -42, 7, 8, 9};
	ContainerType	container(intArray, intArray+(sizeof(intArray)/sizeof(int)));

	for (typename ContainerType::iterator it = container.begin();
		 it != container.end();
		 ++it)
	{
		const int&	elem = *it;
		std::cout << elem << " at " << &elem << '\n';
	}

	typename ContainerType::iterator it;

	it = easyfind(container, 3);
	std::cout << "Found 3 at " << &(*it) << '\n';

	it = easyfind(container, 5);
	std::cout << "Found 5 at " << &(*it) << '\n';

	it = easyfind(container, -42);
	std::cout << "Found -42 at " << &(*it) << '\n';

	it = easyfind(container, 9);
	std::cout << "Found 9 at " << &(*it) << '\n';

	it = easyfind(container, 0);
	if (it == container.end())
		std::cout << "Cannot find 0, got the end iterator instead\n";
}

int	main()
{
// Sequence containers
	println("Testing a std::vector (dynamic array) of ints");
	test<std::vector<int> >();
	println("------------------------------------------------");

	println("Testing a std::list (doubly linked list) of ints");
	test<std::list<int> >();
	println("------------------------------------------------");

	println("Testing a std::deque (double-ended queue) of ints");
	test<std::deque<int> >();
	println("------------------------------------------------");

// The only associative containers we can test on
	println("Testing a std::set (balanced binary tree) of ints");
	test<std::set<int> >();
	println("------------------------------------------------");
	
	println("Testing a std::multiset (balanced binary tree) of ints");
	test<std::multiset<int> >();
	println("------------------------------------------------");

// Everything else is not C++98...
}
