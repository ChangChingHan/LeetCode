#include "stdafx.h"


bool judgeCircle(string moves) 
{
	int count = moves.length();
	int i = 0;
	int v_dis = 0;
	int h_dis = 0;

	for (i = 0; i < count; i++)
	{
		if (moves.at(i) == 'R' || moves.at(i) == 'L')
		{
			if (moves.at(i) == 'R')
			{
				h_dis++;
			} 
			else
			{
				h_dis--;
			}
		} 
		else
		{
			if (moves.at(i) == 'U')
			{
				v_dis++;
			} 
			else
			{
				v_dis--;
			}
		}
	}

	if ((h_dis + v_dis) == 0)
	{
		return true;
	}
	return false;
}