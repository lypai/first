#include <string>
#include <iostream>
using namespace std;

int main()
{
	string from;
	getline(cin, from);
	string to;
	getline(cin, to);
	string sentence;
	getline(cin, sentence);
	while(sentence.find(from)!= string::npos && to.find(from) == string::npos)
	{
		sentence.replace(sentence.find(from), from.size(), to);
	}
	cout << sentence << "\n";
	system("pause");
	return 0;
}