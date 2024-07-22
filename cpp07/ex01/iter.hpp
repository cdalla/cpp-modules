#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	printFunct(T& element)
{
	std::cout << "this an element of the array: " << element << std::endl;
	
	return ;
}

// template <typename T>
// void iter (T array[], int len, void f(T element))
// {
// 	for (int i = 0; i < len; i++)
// 	{
// 		f(array[i]);
// 	}
	
// 	return ;
// }

template <typename T>
void iter (T array[], int len, void f(T& element))
{
	for (int i = 0; i < len; i++)
	{
		f(array[i]);
	}
	
	return ;
}

template <typename T>
void iter (T array[], int len, void f(const T& element))
{
	for (int i = 0; i < len; i++)
	{
		f(array[i]);
	}
	
	return ;
}

// template <typename T>
// void iter (T array[], int len, void f(volatile T& element))
// {
// 	for (int i = 0; i < len; i++)
// 	{
// 		f(array[i]);
// 	}
	
// 	return ;
// }

#endif