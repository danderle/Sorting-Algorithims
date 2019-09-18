#include <iostream>
#include <algorithm>
#include <vector>

class BubbleSort
{
public:
	BubbleSort()
	{
		Initialize();
		Output();
		getchar();
	}

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
	void Output()
	{
		std::cout << "NOT SORTED\n";
		Print(numArr, ArrLength);
		Sort(numArr, ArrLength);
		std::cout << "\nSORTED\n";
		Print(numArr, ArrLength);
	}

	static const int ArrLength = 50;
	std::vector<int> nums;
	int numArr[ArrLength];

};