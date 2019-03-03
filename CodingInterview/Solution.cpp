#include "stdafx.h"
#include "Solution.h"


Solution::Solution()
{
}


Solution::~Solution()
{
}

bool Solution::FindInPartiallySortedMatrix(int target, vector<vector<int> > array)
{
	int rowLength = array.size();
	int colLength;

	if (rowLength == 0)
		return false;

	colLength = array[0].size();

	int row = 0, col = colLength - 1;
	while (row < rowLength && col >= 0)
	{
		if (array[row][col] == target)
		{
			return true;
		}
		else if (target < array[row][col])
		{
			col--;
		}
		else if (target > array[row][col])
		{
			row++;
		}
	}

	return false;
}

bool Solution::DuplicationInArray(int numbers[], int length, int* duplication)
{
	if (numbers == nullptr || length <= 1)
		return false;

	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	for (int i = 0; i < length; i++)
	{
		while (i != numbers[i])
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}

			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}

	return false;
}
