#include "stdafx.h"
#include "Solution.h"
#include <stack>

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

void Solution::ReplaceSpaces(char *str, int length)
{
	if (str == nullptr || length == 0 || str[0] == '\0')
		return;

	int originalLength = 0, spacesNumber = 0;

	while (str[originalLength] != '\0')
	{
		if (str[originalLength] == ' ')
		{
			spacesNumber++;
		}
		originalLength++;
	}

	int newLength = originalLength + spacesNumber * 2;
	if (newLength > length)
	{
		return;
	}

	int pOriginal =  originalLength;
	int pNew = newLength;

	while (pOriginal >= 0 && pNew > pOriginal)
	{
		if (str[pOriginal] == ' ')
		{
			str[pNew--] = '0';
			str[pNew--] = '2';
			str[pNew--] = '%';
		}
		else
		{
			str[pNew--] = str[pOriginal];
		}

		pOriginal--;
	}
}

vector<int> Solution::PrintListInReversedOrder(ListNode* head)
{
	stack<ListNode*> nodes;
	vector<int> result;

	ListNode* node = head;
	while (node != nullptr)
	{
		nodes.push(node);
		node = node->next;
	}

	while (!nodes.empty())
	{
		result.push_back(nodes.top()->val);
		nodes.pop();
	}

	return result;
}
