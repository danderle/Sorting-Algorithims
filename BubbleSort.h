#include <iostream>
#include <algorithm>
#include <vector>

class BubbleSort
{
public:
	//Default constructor
	BubbleSort()
	{
		Initialize();
		Output();
		getchar();
	}

	//Where the magic happens
	void Sort(int arr[], const int arrSize)
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