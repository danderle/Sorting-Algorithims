#include <iostream>
#include <algorithm>
#include <vector>

class InsertionSort
{
public:
	InsertionSort()
	{
		nums.resize(ArrLength);
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			nums[i] = i + 1;
		}
		std::random_shuffle(nums.begin(), nums.end());
		std::copy(nums.begin(), nums.end(), numArr);

		std::cout << "NOT SORTED\n";
		Print(numArr, ArrLength);
		Sort(numArr, ArrLength);
		std::cout << "\nSORTED\n";
		Print(numArr, ArrLength);

		getchar();
	}

	void Sort(int arr[], const int arrSize)
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
	static const int ArrLength = 50;
	std::vector<int> nums;
	int numArr[ArrLength];

};