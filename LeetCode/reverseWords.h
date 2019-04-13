#include "stdafx.h"

string reverseWords(string s) 
{
	string result = "";
	vector<string> words;

	if(s.length() == 0)
		return "";

	char* buffer = new char[s.length()+1];
	memcpy(buffer,s.c_str(),s.length());
	buffer[s.length()] = '\0';

	char* tocken = strtok(buffer," ");
	words.push_back(tocken);
	
	while (tocken != NULL)
	{
		tocken = strtok(NULL," ");
		if(tocken != NULL)
			words.push_back(tocken);
	}

	int count = words.size();
	int string_index = 0;
	for (int index=0; index<count; index++)
	{
		string word = words[index];
		int word_index = word.length()-1;
		for (word_index; word_index>=0; word_index--)
		{
			buffer[string_index++] = word.at(word_index);
		}

		if(index+1 < count)
			buffer[string_index++] = ' ';
	}
	buffer[string_index++] = '\0';
	result = buffer;
	delete[] buffer;

	return result;
}