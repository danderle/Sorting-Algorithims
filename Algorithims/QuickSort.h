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
		ArrSize = arrSize;
		DoQuickSort(arr, 0, arrSize - 1);
	}

private:
	//Partitions the array according to most right number in array and then sorts to the left and to right
	void DoQuickSort(int arr[], int low, int high)
	{
		if (low < high)
		{
			int partition = Partition(arr, low, high);
			Print(arr, ArrSize);
			DoQuickSort(arr, low, partition);
			DoQuickSort(arr, partition + 1, high);
		}
	}
	//compares the indexed number to the right with those to the left
	int Partition(int arr[], int low, int high)
	{
		int i = low - 1;
		int j = low;

		for (; j < high; j++)
		{
			if (arr[j] <= arr[high])
			{
				i++;
				std::swap(arr[i], arr[j]);
			}
		}
		i++;
		std::swap(arr[i], arr[j]);
		return --i;
	}
	int ArrSize;
};