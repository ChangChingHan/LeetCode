#include "stdafx.h"

bool check(int mod, int left)
{
	int r = left % mod;

	if (r == 0)
	{
		return true;
	}
	return false;
}
int char_toint(int a)
{
	if
}

vector<int> selfDividingNumbers(int left, int right) 
{
	vector<int> output;
	char num[6];

	for (left; left <= right; left++)
	{
		if (left % 10 == 0)
		{
			continue;
		}

		itoa(left,num,10);
		//num = to_string(left);

		bool b = false;
		switch(strlen(num))
		{
		case 1:
			output.push_back(left);
			break;
		case 2:
			b = check(atoi(&num[0]),left)&check(atoi(&num[1]),left);
			if(b == true)
				output.push_back(left);

			break;
		case 3:
			b = check(atoi(&num[0]),left)&check(atoi(&num[1]),left)&check(atoi(&num[2]),left);
			if(b == true)
				output.push_back(left);

			break;
		case 4:
			b = check(atoi(&num[0]),left)&check(atoi(&num[1]),left)&check(atoi(&num[2]),left)&check(atoi(&num[3]),left);
			if(b == true)
				output.push_back(left);
			break;
		case 5:
			break;
		}
	}
	return output;
}



