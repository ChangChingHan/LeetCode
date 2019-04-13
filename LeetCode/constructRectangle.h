#include "stdafx.h"

vector<int> constructRectangle(int area)
{
	vector<int> vresult;
	int rest = 0;
	int difference = area;
	int l_length = 0;
	int w=0,l=0;

	for (int w_length = 1; w_length <= area; w_length++)
	{
		rest = area % w_length;
		if (rest == 0)
		{
			l_length = area / w_length;
			if(l_length < w_length)
				break;

			if (abs(l_length-w_length) < difference)
			{
				difference = abs(l_length-w_length);
				w = w_length;
				l = l_length;
			}
		}
	}
	vresult.push_back(l);
	vresult.push_back(w);

	return vresult;
}