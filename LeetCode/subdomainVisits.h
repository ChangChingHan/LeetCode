#include "stdafx.h"

vector<string> prepareDomainString()
{
	//["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]

	vector<string> str;
	str.push_back("900 google.mail.com");
	str.push_back("50 yahoo.com");
	str.push_back("1 intel.mail.com");
	str.push_back("5 wiki.org");

	return str;
}


int findDomain(vector<pair<string,int>> pairDomain, string domain)
{
	int count = pairDomain.size();

	for (int i = 0; i < count ; i++)
	{
		if (pairDomain[i].first.compare(domain) == 0)
		{
			return i;
		}
	}

	return -1;
}

vector<string> subdomainVisits(vector<string>& cpdomains) 
{
	vector<string> result;
	vector<pair<string,int>> pairDomain;
	char buffer[64];
	int count = cpdomains.size();

	for (int i = 0; i < count; i++)
	{
		int len = cpdomains[i].length();
		bool space = false;
		int times = 0;
		int shiftlength = 0;
		int space_position = 0;

		for (int j = 0; j < len; j++)
		{
			if (cpdomains[i][j] == ' ')
			{
				space = true;
				times = atoi(cpdomains[i].substr(0,j).c_str());
				space_position = j;

				string sub_string = cpdomains[i].substr((j+1),(len-j));
				pair<string,int> p;
				p.first = sub_string;
				p.second = times;
				pairDomain.push_back(p);

				sprintf_s(buffer,"%d %s",times,sub_string.c_str());
				result.push_back(buffer);

				break;
			} 
		}

		for (int k = (len-1); k > space_position; k--)
		{
			if (cpdomains[i][k] == '.')
			{
				string sub_string = cpdomains[i].substr((k+1),(len-k));
				int index = 0;

				if ((index = findDomain(pairDomain, sub_string)) != -1)
				{
					pairDomain[index].second += times;
					sprintf_s(buffer,"%d %s",pairDomain[index].second,sub_string.c_str());
					result[index] = buffer;
				}
				else
				{
					pair<string,int> p;
					p.first = sub_string;
					p.second = times;
					pairDomain.push_back(p);

					sprintf_s(buffer,"%d %s",times,sub_string.c_str());
					result.push_back(buffer);
				}
			}
		}
	}

	return result;
}
