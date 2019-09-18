#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

//Abstract class for all Sorting algorithims to output default example
class iSort
{
public:
	//Default constructor
	iSort()
	{
		Initialize();
	}

	//Sorting algorithim to override
	virtual void Sort(int arr[], const int arrSize) = 0;

	//Prints an array
	void Print(int arr[], const int arrSize) const
	{
		std::cout << "-";
		for (int i = 0; i < arrSize; i++)
		{
			std::cout << arr[i] << "-";
		}
		std::cout << std::endl;
	}

	//Prints the unsorted and sorted arrays
	void OutputExample()
	{
		std::cout << "NOT SORTED\n";
		Print(numArr, ArrLength);
		Sort(numArr, ArrLength);
		std::cout << "\nSORTED\n";
		Print(numArr, ArrLength);

		getchar();
	}

private:
	//Initializes a vector with increasing numbers, 
	//then shuffels the vector and then copies it to the array to be sorted
	void Initialize()
	{
		nums.resize(ArrLength);
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			nums[i] = i + 1;
		}
		std::random_shuffle(nums.begin(), nums.end());
		std::copy(nums.begin(), nums.end(), numArr);
	}

	//Defines the array length
	static const int ArrLength = 50;

	//Vector is only used to create the shuffeled array
	std::vector<int> nums;

	//the array to be sorted
	int numArr[ArrLength];
};