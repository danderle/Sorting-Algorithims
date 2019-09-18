#pragma once
#include "iSort.h"

class BubbleSort : public iSort
{
public:
	//Default constructor calls the base constructor
	BubbleSort()
		: iSort()
	{}

	//Where the magic happens
	virtual void Sort(int arr[], const int arrSize) override
	{
		bool sorted = false;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < arrSize - 1; i++)
			{
				if (arr[i] > arr[i + 1])
				{
					std::swap(arr[i], arr[i + 1]);
					sorted = false;
				}
				Print(arr, arrSize);
			}
		}
	}
};