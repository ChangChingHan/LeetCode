// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "rob.h"
//#include "mergeTrees.h"
// #include "removeElement.h"
// #include "findComplement.h"
// #include "reverseWords.h"
// #include "findWords.h"
// #include "matrixReshape.h"
// #include "reverseString.h"
// #include "fizzBuzz.h"
//#include "averageOfLevels.h"
//#include "singleNumber.h"
//#include "maxDepth.h"
//#include "reverseLinkedList.h"
//#include "detectCapitalUse.h"
//#include "findDisappearedNumbers.h"
//#include "findTheDifference.h"
//#include "canConstruct.h"
//#include "getMinimumDifference.h"
//#include "printNumber.h"
//#include "titleToNumber.h"
//#include "findRestaurant.h"
//#include "majorityElement.h"
//#include "containsDuplicate.h"
//#include "invertTree.h"
//#include "merge.h"
#include "subdomainVisits.h"

void fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
{
	int count = A.size();
	int nresult = 0;

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			for (int k = 0; k < count; k++)
			{
				int n = A[i] + B[j] + C[k];
				vector<int>::iterator it = find(D.begin(),D.end(),(n*-1));
				if (it != D.end())
				{
					nresult++;
					break;
				}
			}
		}
	}
}

#include "invertTree.h"
int _tmain(int argc, _TCHAR* argv[])
{
	bool n = compareTree(prepareTreeData());
	/*int num = 38;
	char buffer[16];
	sprintf(buffer,"%d",num);
	int count = strlen(buffer);
	int result = 0;

	while(1)
	{
		result = 0;
		for (int i = 0 ; i < count; i++)
		{
			result += (int)(buffer[i]-0x30);
		}
		if(result < 10)
			break;
		sprintf(buffer,"%d",result);
		count = strlen(buffer);
	}*/

	

	return 0;
}

