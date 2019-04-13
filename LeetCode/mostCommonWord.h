#include "stdafx.h"

string ToUpper(string s) 
{
	int count = s.length();
	for (int i = 0; i < count; i++)
		s[i]=tolower(s[i]);
	return s;
}

int FindWords(vector<pair<string,int>> words, string word)
{
	int count = words.size();
	word = ToUpper(word);
	
	for (int i = 0; i < count; i++)
	{
		if (words[i].first.compare(word) == 0)
		{
			return i;
		}
	}

	return -1;
}

string mostCommonWord() 
{
	string paragraph = "Bob";
	vector<string> banned;
	banned.push_back("hit");

	vector<pair<string,int>> words;

	if (paragraph[paragraph.length()-1] != '.')
	{
		paragraph += ".";
	}
	char buffer[1000];
	sprintf(buffer,"%s",paragraph.c_str());

	int count = strlen(buffer);
	int index = 0;

	for (int i = 0; i < count; i++)
	{
		if (buffer[i] == ' ' || buffer[i] == ',' || buffer[i] == '.' ||
			buffer[i] == '!' || buffer[i] == '?' || buffer[i] == 0x27 ||
			buffer[i] == ';')
		{
			string word = paragraph.substr(index, i - index);
			int r = FindWords(words,word);

			if (r != -1)
			{
				words[r].second++;
			} 
			else
			{
				pair<string,int> p;
				p.first = ToUpper(word);
				p.second = 1;
				words.push_back(p);
			}

			for (int j = i+1; j < count; j++)
			{
				if (!(buffer[j] == ' ' || buffer[j] == ',' || buffer[j] == '.' ||
					buffer[j] == '!' || buffer[j] == '?' || buffer[j] == 0x27 ||
					buffer[j] == ';'))
				{
					i = j;
					index = i;
					break;
				}
			}
		}
	}

	count = banned.size();
	vector<pair<string,int>>::iterator it;
	for (int i = 0; i < count; i++)
	{
		int eraseIdx = FindWords(words,banned[i]);
		if (eraseIdx != -1)
		{
			words.erase(words.begin()+eraseIdx);
		} 
	}
	
	int maxNum = 0;
	index = 0;
	count = words.size();
	for (int i = 0; i < count; i++)
	{
		if (words[i].second > maxNum)
		{
			maxNum = words[i].second;
			index = i;
		}
	}
	
	return words[index].first;
}

