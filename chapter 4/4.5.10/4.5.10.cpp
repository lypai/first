#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
	cout << "Enter value pairs: ";
	string values;
	getline(cin, values);
	cout << "Enter template: ";
	string templt;
	getline(cin, templt);
	smatch result;
	while(regex_search(templt, result, regex("\\[[^\\[]*\\]")))
	{
		string valName = result[0];
		valName = valName.substr(1, valName.size() - 2) + "=";
		string reg = valName + "[^,]*,";
		smatch innerResult;
		if(regex_search(values, innerResult, regex(reg)))
		{
			string val = innerResult[0];
			//cout << "val = " << val << "|" << endl;
			val = val.substr(valName.size(), val.size() - 1);
			val = val.substr(0, val.size() - 1);
			//cout << "val = " << val << "|" << endl;
			size_t start_pos = templt.find(result[0]);
			templt.replace(start_pos, result[0].length(), val);
		}
		else break;
	}
	cout << "templare now: " << templt << endl;
	system("pause");
	return 0;
}