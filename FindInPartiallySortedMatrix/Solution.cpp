#include "stdafx.h"
#include "Solution.h"


Solution::Solution()
{
}


Solution::~Solution()
{
}

bool Solution::FindInPartiallySortedMatrix(int target, vector<vector<int> > array) {
	int rowLength = array.size();
	int colLength;

	if (rowLength == 0)
		return false;

	colLength = array[0].size();

	int row = 0, col = colLength - 1;
	while (row < rowLength && col >= 0) {
		if (array[row][col] == target) {
			return true;
		}
		else if (target < array[row][col]) {
			col--;
		}
		else if (target > array[row][col]) {
			row++;
		}
	}

	return false;
}
