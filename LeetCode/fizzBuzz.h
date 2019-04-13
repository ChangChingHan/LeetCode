#include "stdafx.h"

vector<string> fizzBuzz(int n) 
{
	vector<string> result;

	for (int index = 1; index <= n; index ++)
	{
		if (index % 15 == 0)
		{
			result.push_back("FizzBuzz");
		}
		else if (index % 3 == 0)
		{
			result.push_back("Fizz");
		}
		else if (index % 5 == 0)
		{
			result.push_back("Buzz");
		}
		else
		{
			char buffer[8];
			sprintf(buffer,"%d",index);
			result.push_back(buffer);
		}
	}

	return result;
}

