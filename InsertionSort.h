#pragma once
#include "iSort.h"

class InsertionSort : public iSort
{
public:
	//Default constructor calls the base constructor
	InsertionSort()
		: iSort()
	{}

	//Where the magic happens
	virtual void Sort(int arr[], const int arrSize) override
	{
		int key, j;
		for (int i = 1; i < arrSize; i++)
		{
			key = arr[i];
			j = i - 1;
			while (j >= 0 && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				arr[j] = key;
				j--;
				Print(arr, arrSize);
			}
		}
	}
};