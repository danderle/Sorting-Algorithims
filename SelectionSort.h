#include <iostream>
#include <algorithm>
#include <vector>

class SelectionSort
{
public:
	//Default constructor
	SelectionSort()
	{
		Initialize();
		Output();
		getchar();
	}

	//Where the magic happens
	void Sort(int arr[], const int arrSize)
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

	//Prints the unsorted and sorted arrays
	void Output()
	{
		std::cout << "NOT SORTED\n";
		Print(numArr, ArrLength);
		Sort(numArr, ArrLength);
		std::cout << "\nSORTED\n";
		Print(numArr, ArrLength);
	}

	//Defines the array length
	static const int ArrLength = 50;
	//Vector is only used to create the shuffeled array
	std::vector<int> nums;
	//the array to be sorted
	int numArr[ArrLength];

};