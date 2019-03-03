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
				{1,2,8,9},
				{2,4,9,12},
				{4,7,10,13},
				{6,8,11,15}
			};

			int i, j;
			vector<vector<int>> array(4);
			for (i = 0; i < array.size(); i++)
				array[i].resize(4);

			for (i = 0; i<array.size(); i++)
			{
				for (j = 0; j<array[0].size(); j++)
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

	};
}