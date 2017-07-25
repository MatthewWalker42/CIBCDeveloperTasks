#pragma once
#include <vector>
#include <iostream>

template<class T>
class CircularArray
{
private:
	typename std::vector<T> arr; //array where elements are stored
	typename std::vector<T>::iterator start; //Start of the circular array (oldest element)
	typename std::vector<T>::iterator end; //End of circular array (where new elements will be placed)

	//Determines if the start iterator needs to be incremented
	void getNewStart()
	{
		if (start == end)
		{
			T empty;
			if (*start != empty)
				incrementStart();
		}
	}

	//Increments the start iterator.
	// If it reaches end of the array, it loops back to beginning of the array
	void incrementStart()
	{
		start++;
		if (start == arr.end())
			start = arr.begin();
	}
	//Increments the end iterator.
	// If it reaches end of the array, it loops back to beginning of the array
	void incrementEnd()
	{
		end++;
		if (end == arr.end())
			end = arr.begin();
	}

public:
	
	CircularArray(int size)
	{
		arr.resize(size);
		start = arr.begin();
		end = arr.begin();
	}

	~CircularArray()
	{

	}

	T at(int index)
	{
		return arr.at(index);
	}

	unsigned size()
	{
		return arr.size();
	}

	int numElements()
	{
		T empty;
		int num = 0;
		for (unsigned i = 0; i < arr.size(); i++)
		{
			if (arr.at(i) != empty)
				num++;
		}
		return num;
	}

	void add(T element)
	{
		getNewStart();
		*end = element;
		incrementEnd();
	}

	void remove()
	{
		T empty;
		if (*start != empty)
		{
			*start = empty;
			incrementStart();
		}

	}

};

