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
		Divide(arr, 0, arrSize-1, arrSize);
	}

private:
	//Divides the array into smaller subsections recursively
	void Divide(int arr[], int l, int r, const int arrSize)
	{
		if (l < r)
		{
			int m = (r + l) / 2;
			Divide(arr, l, m, arrSize);
			Divide(arr, m + 1, r, arrSize);

			Merge(arr, l, m, r, arrSize);
		}
	}
	//Merges the left and right sections
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