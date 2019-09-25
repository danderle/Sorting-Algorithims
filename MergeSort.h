#pragma once
#include "iSort.h"

class MergeSort : public iSort
{
public:
	//Default constructor calls the base constructor
	MergeSort()
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

private:
	void Merge(int arr[], int l, int m, int r, const int arrSize)
	{
		const int l1 = m - l + 1;
		const int l2 = r - m;
		int* arrL = new int[l1];
		int* arrR = new int[l2];

		for (int i = 0; i < l1; i++)
		{
			arrL[i] = arr[l + i];
		}
		for (int i = 0; i < l2; i++)
		{
			arrR[i] = arr[m + 1 + i];
		}

		int i1 = 0;
		int i2 = 0;
		int iOrg = 0;
		
		while (i1 < l1 && i2 < l2)
		{
			if (arrL[i1] <= arrR[i2])
			{
				arr[l + iOrg] = arrL[i1];
				i1++;
				Print(arr, arrSize);
			}
			else
			{
				arr[l + iOrg] = arrR[i2];
				i2++;
				Print(arr, arrSize);
			}
			iOrg++;
		}
		
		while (i2 < l2)
		{
			arr[l + iOrg] = arrR[i2];
			i2++;
			iOrg++;
			Print(arr, arrSize);
		}

		while (i1 < l1)
		{
			arr[l + iOrg] = arrL[i1];
			i1++;
			iOrg++;
			Print(arr, arrSize);
		}
		delete[] arrL;
		delete[] arrR;
	}
};