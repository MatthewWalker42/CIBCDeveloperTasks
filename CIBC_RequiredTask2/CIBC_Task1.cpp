// CIBC_Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CircularArray.h"
#include <string>


int main()
{
	CircularArray<std::string> test(2);
	CircularArray <int> test2(5);
	std::cout << "Number of elements: " << std::to_string(test2.numElements()) << std::endl;
	test2.add(4);
	test2.add(7);
	test2.add(1);
	test2.add(9);
	test2.add(15);
	test2.remove();
	//test2.add(24);
	std::cout << "Number of elements: " << std::to_string(test2.numElements()) << std::endl;
	//Will still print out null element values because they are created when array is initialized
	for (auto e:test2)
	{
		std::cout << e << std::endl;
	}
	test.remove();
	std::cout << "Number of elements: " << std::to_string(test.numElements()) << std::endl;
	test.add("foo");
	test.add("bar");
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

	if (test.isEmpty()) //should be empty
		std::cout << "Empty" << std::endl;
	else
		std::cout << "Not empty" << std::endl;

	std::cout << *test2.front() << std::endl; //Should print 7
    return 0;
}

