#pragma once

#include<vector>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL)
	{

	}
};

class Solution
{
public:
	bool FindInPartiallySortedMatrix(int target, vector<vector<int> > array);
	bool DuplicationInArray(int numbers[], int length, int* duplication);
	void ReplaceSpaces(char *str, int length);
	vector<int> PrintListInReversedOrder(ListNode* head);
	Solution();
	~Solution();
};


