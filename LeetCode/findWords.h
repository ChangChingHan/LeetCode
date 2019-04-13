#include "stdafx.h"

bool checkSameLine(string linestring, string word)
{
	bool result = true;
	int word_count = word.length();
	char c;
	int line_count = linestring.length();
	bool samechar = false;

	for (int word_index = 0; word_index < word_count; word_index++)
	{
		samechar = false;
		c = word.at(word_index);
		c = toupper(c);

		for (int line_index = 0; line_index < line_count; line_index++)
		{
			if (linestring.at(line_index) == c)
			{
				samechar = true;
				break;
			}
		}
		
		if (samechar == false)
		{
			result = false;
			break;
		}
	}

	return result;
}

vector<string> findWords(vector<string>& words) 
{
	string first_line = "QWERTYUIOP";
	string secon_line = "ASDFGHJKL";
	string third_line = "ZXCVBNM";
	bool sameLine = false;
	vector<string> filter_word;
	int count = words.size();
	for (int index = 0; index < count; index++)
	{
		string str = words[index];
	
		if (checkSameLine(first_line, str) == true)
		{
			filter_word.push_back(str);
			continue;
		}

		if (checkSameLine(secon_line, str) == true)
		{
			filter_word.push_back(str);
			continue;
		}

		if (checkSameLine(third_line, str) == true)
		{
			filter_word.push_back(str);
			continue;
		}
	}

	return filter_word;
}