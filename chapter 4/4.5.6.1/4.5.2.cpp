#include <string>
#include <iostream>
using namespace std;

int main()
{
	string sentence;
	getline(cin, sentence);
	int pos;
	while((pos = sentence.find("  "))!= string::npos)
	{
		sentence = sentence.substr(0, pos) + sentence.substr(pos + 1); 
	}
	cout << sentence << "\n";
	system("pause");
	return 0;
}