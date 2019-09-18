#pragma once
#include "iSort.h"

class SelectionSort : public iSort
{
public:
	//Default constructor calls the base constructor
	SelectionSort()
		:iSort()
	{}

	//Where the magic happens
	virtual void Sort(int arr[], const int arrSize) override
	{
		for (int i = 0; i < arrSize - 1; i++)
		{
			int min = arr[i];
			int minIndex = i;
			bool minFound = false;
			for (int j = i + 1; j < arrSize; j++)
			{
				if (min > arr[j])
				{
					minFound = true;
					min = arr[j];
					minIndex = j;
				}
			}
			if (minFound)
				std::swap(arr[i], arr[minIndex]);
			Print(arr, arrSize);
		}
	}
};