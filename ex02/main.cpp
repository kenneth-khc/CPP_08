/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:22:26 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/10 18:16:37 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "MutantStack.hpp"

template<typename Type>
void	println(const Type& t)
{
	std::cout << t << '\n';
}

void	testMutantStack()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.top() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);
}

template <typename Container>
void	testContainer()
{
	Container	c;

	c.push_back(5);
	c.push_back(17);

	std::cout << c.back() << std::endl;
	c.pop_back();
	std::cout << c.back() << std::endl;

	c.push_back(3);
	c.push_back(5);
	c.push_back(737);
	//[...]
	c.push_back(0);

	typename Container::iterator	it = c.begin();
	typename Container::iterator	ite = c.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	Container	cc(c);
}

int	main()
{
#if 1
	{
		MutantStack<std::string>	ms;
		std::string	arr[] = {"one", "two", "three"};
		for (unsigned int i = 0; i < sizeof(arr)/sizeof(*arr); ++i)
		{
			ms.push(arr[i]);
		}
		{
			println("Testing copy construct...");
			MutantStack<std::string>	msCopy(ms);
			for (MutantStack<std::string>::iterator it = msCopy.begin();
				 it != msCopy.end();
				 ++it)
			{
				std::cout << *it << '\n';
			}
		}
		{
			MutantStack<std::string>	anotherMS;
			anotherMS = ms;
			println("Testing copy assignment...");
			for (MutantStack<std::string>::iterator it = anotherMS.begin();
				 it != anotherMS.end();
				 ++it)
			{
				std::cout << *it << '\n';
			}
		}
		for (MutantStack<std::string>::iterator it = ms.begin();
			 it != ms.end();
			 ++it)
		{
			*it += *it;
			std::cout << *it << '\n';
		}
		/*for (MutantStack<std::string>::const_iterator it = ms.cbegin();*/
		/*	 it != ms.end();*/
		/*	 ++it)*/
		/*{*/
		/*	*it += *it;*/
		/*	std::cout << *it << '\n';*/
		/*}*/
	
	}
#endif
#if 0
	println("Testing MutantStack of ints...");
	testMutantStack();
	println("------------------------------");

	println("Testing list of ints...");
	testContainer< std::list<int> >();
	println("------------------------------");

	println("Testing vector of ints...");
	testContainer< std::vector<int> >();
	println("------------------------------");

	println("Testing deque of ints...");
	testContainer< std::deque<int> >();
	println("------------------------------");
#endif
}
