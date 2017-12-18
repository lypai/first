#include <string>
#include <iostream>
using namespace std;

int main()
{
	string stop_words;
	getline(cin, stop_words);

	string sentence;
	getline(cin, sentence);

	int stopWordsCount = 0;
	for(int i = 0; i < stop_words.size(); i++)
	{
		if(stop_words[i] == ',') 
			stopWordsCount++;
	}
	string* stopWords = new string[stopWordsCount + 1];
	int j = 0;
	string word = "";
	for(int i = 0; i < stop_words.size(); i++)
	{
		if(stop_words[i] != ',') 
		{
			word += stop_words[i];
		}
		else 
		{
			stopWords[j] = word;
			j++;
			word = "";
		}
		if(i == (stop_words.size() - 1))
		{
			stopWords[j] = word;
			j++;
		}
	}
	for(int i = 0; i < j; i++)
	{
		while(sentence.find(stopWords[i] + " ")!= string::npos || sentence.find(" " + stopWords[i])!= string::npos)
		{
			if(sentence.find(stopWords[i] + " ")!= string::npos) 
				sentence.replace(sentence.find(stopWords[i] + " "), stopWords[i].size() + 1, "");
			if(sentence.find(" " + stopWords[i])!= string::npos) 
				sentence.replace(sentence.find(" " + stopWords[i]), stopWords[i].size() + 1, "");
			
		}
	}
	cout << sentence << endl;
	system("pause");
	return 0;
}