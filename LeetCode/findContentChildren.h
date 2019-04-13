#include "stdafx.h"

void sort(vector<int>& g)
{
	while (1)
	{
		int g_count = g.size();
		bool isswap = false;
		for (int index = 1; index< g_count;index++)
		{
			if (g[index-1]>g[index])
			{
				swap(g[index-1],g[index]);
			}
		}
		if (isswap == false)
		{
			break;
		}
	}
}

int findContentChildren(vector<int>& g, vector<int>& s) 
{
	sort(g);
	sort(s);

	int g_count = g.size();
	
	vector<int> v;
	
	for (int gindex = 0; gindex < g_count; gindex++)
	{
		int s_count = s.size();
		for (int sindex = 0; sindex < s_count; sindex++)
		{
			if (g[gindex] == s[sindex])
			{
				v.push_back(g[gindex]);
				s.erase(s.begin()+sindex);
				break;
			}
		}
	}

	int result = v.size();
	return result;
}
