#pragma once
#include "iSort.h"

class QuickSort : public iSort
{
public:
	QuickSort()
		: iSort()
	{}

	//Sorting algorithim to override
	void Sort(int arr[], const int arrSize) override
	{
		DoQuickSort(arr, 0, arrSize - 1);
	}

private:
	void DoQuickSort(int arr[], int low, int high)
	{
		if (low < high)
		{
			int partition = Partition(arr, low, high);

			DoQuickSort(arr, low, partition);
			DoQuickSort(arr, partition + 1, high);
		}
	}
	int Partition(int arr[], int low, int high)
	{
		int i = low - 1;
		int j = low;

		for (; j < high-1; j++)
		{
			if (arr[j] <= arr[high])
			{
				i++;
				std::swap(arr[i], arr[j]);
			}
		}
		i++;
		std::swap(arr[i], arr[j]);
		return i;
	}
	
};