// CIBC_Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CircularArray.h"
#include <string>


int main()
{
	CircularArray<std::string> test(2);
	test.remove();
	std::cout << "Number of elements: " << std::to_string(test.numElements()) << std::endl;
	test.add("Hey");
	test.add("Supp");
	std::cout << "Number of elements: " << std::to_string(test.numElements()) << std::endl;
	for (unsigned i=0; i < test.size(); i++)
	{
		std::cout << test.at(i) << std::endl;
	}
	test.add("New");
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Number of elements: " << std::to_string(test.numElements()) << std::endl;
	for (unsigned i = 0; i < test.size(); i++)
	{
		std::cout << test.at(i) << std::endl;
	}
	test.remove();
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Number of elements: " << std::to_string(test.numElements()) << std::endl;
	for (unsigned i = 0; i < test.size(); i++)
	{
		std::cout << test.at(i) << std::endl;
	}
	test.remove();
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Number of elements: " << std::to_string(test.numElements()) << std::endl;
	for (unsigned i = 0; i < test.size(); i++)
	{
		std::cout << test.at(i) << std::endl;
	}
    return 0;
}

