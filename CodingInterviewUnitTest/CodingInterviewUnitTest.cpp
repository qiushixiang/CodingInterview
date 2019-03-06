#include "stdafx.h"
#include "CppUnitTest.h"

#include "Solution.h"
#include "Solution.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CodingInterviewUnitTest
{
	TEST_CLASS(CodingInterviewUnitTest)
	{
	public:

		TEST_METHOD(FindInPartiallySortedMatrix)
		{
			// TODO: 在此输入测试代码
			char tempDate[4][4] =
			{
				{ 1,2,8,9},
				{ 2,4,9,12},
				{ 4,7,10,13},
				{ 6,8,11,15}
			};

			int i, j;
			vector<vector<int>> array(4);
			for (i = 0; i < array.size(); i++)
				array[i].resize(4);

			for (i = 0; i < array.size(); i++)
			{
				for (j = 0; j < array[0].size(); j++)
				{
					array[i][j] = tempDate[i][j];
				}
			}

			Solution solution;
			Assert::AreEqual(true, solution.FindInPartiallySortedMatrix(1, array));
			Assert::AreEqual(true, solution.FindInPartiallySortedMatrix(15, array));
			Assert::AreEqual(true, solution.FindInPartiallySortedMatrix(7, array));

			Assert::AreEqual(false, solution.FindInPartiallySortedMatrix(-1, array));
			Assert::AreEqual(false, solution.FindInPartiallySortedMatrix(5, array));
			Assert::AreEqual(false, solution.FindInPartiallySortedMatrix(20, array));

			Assert::AreEqual(false, solution.FindInPartiallySortedMatrix(5, vector<vector<int>>()));

		}

		TEST_METHOD(DuplicationInArray)
		{
			int test_array_0[7] = { 2, 3, 1, 0, 2, 5, 3 };
			int test_array_1[7] = { 4, 3, 1, 0, 2, 5, 3 };
			int test_array_2[7] = { 4, 3, 1, 0, 2, 5, 6 };
			int test_array_3[7] = { 2, 3, 1, 0, 2, 5, 7 };

			Solution solution;

			int duplication = -1;
			bool result = false;
			result = solution.DuplicationInArray(test_array_0, 7, &duplication);
			Assert::AreEqual(true, result);
			Assert::AreEqual(2, duplication);

			result = solution.DuplicationInArray(test_array_1, 7, &duplication);
			Assert::AreEqual(true, result);
			Assert::AreEqual(3, duplication);

			result = solution.DuplicationInArray(test_array_2, 7, &duplication);
			Assert::AreEqual(false, result);

			result = solution.DuplicationInArray(test_array_3, 7, &duplication);
			Assert::AreEqual(false, result);

			result = solution.DuplicationInArray(nullptr, 7, &duplication);
			Assert::AreEqual(false, result);

			result = solution.DuplicationInArray(test_array_0, 0, &duplication);
			Assert::AreEqual(false, result);

			result = solution.DuplicationInArray(test_array_0, 1, &duplication);
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(ReplaceSpaces)
		{
			Solution solution;

			char test_str_0[100] = "We are happy.";
			solution.ReplaceSpaces(test_str_0, 100);
			Assert::AreEqual(0, strcmp("We%20are%20happy.", test_str_0));

			char test_str_1[100] = "Wearehappy.";
			solution.ReplaceSpaces(test_str_1, 100);
			Assert::AreEqual(0, strcmp("Wearehappy.", test_str_1));

			char test_str_2[100] = "We    are happy.";
			solution.ReplaceSpaces(test_str_2, 100);
			Assert::AreEqual(0, strcmp("We%20%20%20%20are%20happy.", test_str_2));

			char test_str_3[100] = "We are happy.   ";
			solution.ReplaceSpaces(test_str_3, 100);
			Assert::AreEqual(0, strcmp("We%20are%20happy.%20%20%20", test_str_3));

			char test_str_4[100] = "   We are happy.";
			solution.ReplaceSpaces(test_str_4, 100);
			Assert::AreEqual(0, strcmp("%20%20%20We%20are%20happy.", test_str_4));

			char* test_str_5 = nullptr;
			solution.ReplaceSpaces(test_str_5, 100);
			Assert::AreEqual(nullptr, test_str_5);

			char test_str_9[100] = "We are happy.";
			solution.ReplaceSpaces(test_str_9, 0);
			Assert::AreEqual(0, strcmp("We are happy.", test_str_9));

			char test_str_6[100] = "    ";
			solution.ReplaceSpaces(test_str_6, 100);
			Assert::AreEqual(0, strcmp("%20%20%20%20", test_str_6));

			char test_str_7[100] = { '\0' };
			char test_str_8[100] = { '\0' };
			solution.ReplaceSpaces(test_str_7, 100);
			Assert::AreEqual(0, strcmp(test_str_8, test_str_7));

			char test_str_10[100] = "We are happy.";
			solution.ReplaceSpaces(test_str_10, 14);
			Assert::AreEqual(0, strcmp("We are happy.", test_str_10));

		}

		TEST_METHOD(PrintListInReversedOrder)
		{
			Solution solution;

			ListNode* test_head_0 = nullptr;
			ListNode* rear = nullptr;

			for (auto i : { 1,2,3,4,5 })
			{
				auto newNode = new ListNode(i);
				newNode->next = nullptr;

				if (test_head_0 == nullptr)
				{
					test_head_0 = newNode;
				}
				else
				{
					rear->next = newNode;
				}
				rear = newNode;
			}

			vector<int> expect_result0 = { 5,4,3,2,1 };
			auto result = solution.PrintListInReversedOrder(test_head_0);
			for (int i = 0; i < 5; i++)
			{
				Assert::AreEqual(expect_result0[i], result[i]);
			}

			Assert::AreEqual(true, solution.PrintListInReversedOrder(nullptr).empty());

			ListNode* test_head_1 = new ListNode(2);
			Assert::AreEqual((size_t)1, solution.PrintListInReversedOrder(test_head_1).size());
			Assert::AreEqual(2, solution.PrintListInReversedOrder(test_head_1)[0]);
		}

	};
}