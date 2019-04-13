#include "stdafx.h"
#include <bitset>

bool hasAlternatingBits(int n) 
{
	string buf = bitset<32>(n).to_string();

	int i = 31;
	int j = 1;

	while(i >= 0)
	{
		if(n < j)
			break;
		if (i - 1 >= 0)
		{
			if (buf.at(i) == buf.at(i-1))
			{
				cout << buf.at(i);
				cout << buf.at(i-1);
				return false;
			}
		}
		i--;
		j *= 2; 
	}

	return true;  
}