/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:53:34 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/11 10:31:24 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>
#include <deque>
#include "Span.hpp"

template<typename T>
void	println(const T& t)
{
	std::cout << t << '\n';
}

template<typename ContainerType>
void	doBigTest()
{
	ContainerType	bigContainer(1000000);
	std::srand(std::time(0));
	for (typename ContainerType::iterator it = bigContainer.begin();
		 it != bigContainer.end(); ++it)
	{
		int	randNum = std::rand();
		std::cout << randNum << " ";
		*it = randNum;
	}
	std::cout << '\n';
	Span	bigSpan(1000000);
	bigSpan.addNumbersFromRange(bigContainer.begin(), bigContainer.end());
	std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
}

int	main()
{
#if 1
	println("Testing basics...");
	{
		Span	empty = Span();
		try
		{
			empty.addNumber(1);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		Span	sp(5); // construct span of size 5
		Span	spCopy(sp); // copy construct
		empty = sp; // copy assign

		empty.addNumber(1); spCopy.addNumber(1);
		empty.addNumber(3); spCopy.addNumber(3);
		empty.addNumber(1000); spCopy.addNumber(1000);
		empty.addNumber(1001); spCopy.addNumber(1001);
		empty.addNumber(-10000); spCopy.addNumber(-10000);
		std::cout << "Shortest span: " << empty.shortestSpan()
				  << " == " << spCopy.shortestSpan() << '\n';
		std::cout << "Longest span: " << empty.longestSpan()
				  << " == " << spCopy.longestSpan() << '\n';
	}
#endif
#if 0
	println("Testing subject pdf...");
	{
		Span	sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
#endif
#if 0
	println("Testing 10000 numbers and filling it from an int array...");
	{
		int	bigArray[10000];
		for (int i = 0; i < 10000; ++i)
		{
			bigArray[i] = i;
			std::cout << i << " ";
		}
		std::cout << '\n';
		Span	bigSpan(10000);
		bigSpan.addNumbersFromRange(bigArray, bigArray+10000);
		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
	}
#endif
#if 0
	println("Testing 1,000,000 numbers from a vector");
	{
		doBigTest< std::vector<int> >();
	}
	println("Done testing 1,000,000 numbers from a vector");
#endif
#if 0
	println("Testing 1,000,000 numbers from a list");
	{
		doBigTest< std::list<int> >();
	}
	println("Done testing 1,000,000 numbers from a list");
#endif
#if 0
	println("Testing 1,000,000 numbers from a deque");
	{
		doBigTest< std::deque<int> >();
	}
	println("Done testing 1,000,000 numbers from a deque");
#endif
}
