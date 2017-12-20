#include <string>
#include <iostream>
#include <regex>
using namespace std;

bool replace(string& str, const string from, const string to)
{
	size_t start_pos = str.find(from);
    if(start_pos == string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}
	

int main()
{
	string sentence;
	getline(cin, sentence);
	cout << regex_match(sentence, regex("\\*.*_.*_.*\\*"));
	smatch result;
	cout << "=============== before asterisk and underscore ====================" << endl;
		
	while(regex_search(sentence, result, regex("\\*.*_.*_.*\\*")))
	{		
		cout << "=============== in asterisk and underscore ====================" << endl;
		string invalidPart = result[0];
		cout << "invalidPart: " << invalidPart << endl;
		while(replace(invalidPart, "_", "")) {}
		cout << "changed invalidPart: " << invalidPart << endl;
		replace(sentence, result[0], invalidPart);
		//replace(invalidPart.begin(), invalidPart.end(), '_', ' ');

		
	}
	cout << "=============== before underscore and asterisk ====================" << endl;
		
	while(regex_search(sentence, result, regex("_[.\\*]*_")))
	{	
		cout << "=============== in underscore and asterisk ====================" << endl;
		
		string invalidPart = result[0];
		cout << "invalidPart: " << invalidPart << endl;
		while(replace(invalidPart, "*", "")) {}
		cout << "changed invalidPart: " << invalidPart << endl;
		replace(sentence, result[0], invalidPart);
		//replace(invalidPart.begin(), invalidPart.end(), '_', ' ');		
	}
	cout << "=============== before only asterisk ====================" << endl;
		
	while(regex_search(sentence, result, regex("\\*[^\\*]*\\*")))
	{
		cout << "=============== in only asterisk ====================" << endl;
		
		string part = result[0];
		cout << "in while part: " << part << endl;
		while(replace(part, "*", "")) {}
		transform(part.begin(), part.end(), part.begin(),(int (*)(int))toupper);
		replace(sentence, result[0], part);
		cout << "in end of the while sentence: " << sentence << endl;
			
	}
	cout << "=============== before only underscore ====================" << endl;
		
	while(regex_search(sentence, result, regex("_[^_]*_")))
	{
		cout << "=============== in only underscore ====================" << endl;
		
		string part = result[0];
		cout << "in while part: " << part << endl;		
		while(replace(part, "_", "")) {}
		for(int i=0; i < part.size(); ++i)
	    {
			cout << "i = " << i << " part = " << part << endl;
			if(part[i] != ' ')
			{
				part.insert(part.begin()+ ++i, ' ');
			}
        }
		cout << "before main replace" << endl;
		//while(replace(sentence, result[0], part)) {}
		size_t start_pos = sentence.find(result[0]);
    if(start_pos != string::npos)
    sentence.replace(start_pos, result[0].length(), part);
		//replace(sentence, result[0], part);
		cout << "in end of the while sentence: " << sentence << endl;
			
	}
	cout << sentence << endl;
	system("pause");
	return 0;
}