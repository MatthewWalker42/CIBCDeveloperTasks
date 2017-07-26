#pragma once
#include <vector>
#include <iostream>
#include <iterator>

template<class T>
class CircularArray
{
private:
	typename std::vector<T> arr; //array where elements are stored
	typename std::vector<T>::iterator start; //Start of the circular array (oldest element)
	typename std::vector<T>::iterator arrEnd; //End of circular array (where new elements will be placed)

	//Determines if the start iterator needs to be incremented
	void getNewStart()
	{
		if (start == arrEnd)
		{
			T empty{};
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
		arrEnd++;
		if (arrEnd == arr.end())
			arrEnd = arr.begin();
	}

public:
	
	CircularArray(int size)
	{
		arr.resize(size);
		start = arr.begin();
		arrEnd = arr.begin();
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
		T empty{};
		int num = 0;
		for (unsigned i = 0; i < arr.size(); i++)
		{
			if (arr.at(i) != empty)
				num++;
		}
		return num;
	}

	bool isEmpty()
	{
		if (numElements() == 0)
			return true;
		else
			return false;
	}

	void add(T element)
	{
		getNewStart();
		*arrEnd = element;
		incrementEnd();
	}

	void remove()
	{
		if (isEmpty())
			return;
		T empty{};
		if (*start != empty)
		{
			*start = empty;
			incrementStart();
		}

	}

	typename std::vector<T>::iterator begin()
	{
		return start;
	}

	typename std::vector<T>::iterator end()
	{
		return arrEnd;
	}
};

