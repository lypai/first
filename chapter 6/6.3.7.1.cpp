#include <iostream>
#include <string>
#include <regex>
using namespace std;

class IPAddress
{
public:
	string ip;
	IPAddress(string _ip);
	virtual void Print();
};
IPAddress::IPAddress(string _ip)
{
	ip = _ip;
}
void IPAddress::Print()
{
	cout << ip << endl;
}
class IPAddressChecked : public IPAddress
{
	public:
	string ip;
	bool isCorrect;
	IPAddressChecked(string _ip);
	void Print();
};

void IPAddressChecked::Print()
{
	if(isCorrect) cout << ip << " - Correct" << endl;
	else cout << ip << " - Not Correct" << endl;
}

IPAddressChecked::IPAddressChecked(string _ip): IPAddress(_ip)
{
	ip = _ip;
	regex isDigit("[1-9]");
	bool correctIp = false, manyCharacters = false, manyParts = false,
		onlyDigitsAndDots = true, BigPartValue = false;
	int lastDotPosition = 0, dotCount = 0, dotPosition;

	string dotIp = ip;
	for(int i = 0; i < ip.length(); i++)
	{
		if(ip.substr(i, 1) == ".") dotCount++;	
		if((ip.substr(i, 1) != ".") && (! regex_match(ip.substr(i, 1), isDigit))) onlyDigitsAndDots = false;
	}
	
	if(dotCount > 3) manyParts = true;
	if(!manyParts && onlyDigitsAndDots){
		string tempIp = ip;
		string firstOctet = tempIp.substr(0, tempIp.find("."));
		tempIp = tempIp.substr(tempIp.find(".") + 1);
		string secondOctet = tempIp.substr(0, tempIp.find("."));
		tempIp = tempIp.substr(tempIp.find(".") + 1);
		string thirdOctet  = tempIp.substr(0, tempIp.find("."));
		tempIp = tempIp.substr(tempIp.find(".") + 1);
		string fourthOctet = tempIp.substr(0, tempIp.find("."));
		if(firstOctet.length() > 3 || secondOctet.length() > 3 ||
			thirdOctet.length() > 3 || fourthOctet.length() > 3) manyCharacters = true;
	}
	if(!manyParts && !manyCharacters && onlyDigitsAndDots){
	
		string tempIp = ip;
	int firstOctet = atoi(tempIp.c_str());
	int i;
	for (i = 0; tempIp[i] != '.'; i++);	
	tempIp = &tempIp[i + 1];
	//cout << "first octet = "<< firstOctet << endl;
	int secondOctet = atoi(tempIp.c_str());
	for (i = 0; tempIp[i] != '.'; i++);	
	tempIp = &tempIp[i + 1];
	//cout << "second octet = "<< secondOctet << endl;
	int thirdOctet = atoi(tempIp.c_str());
	for (i = 0; tempIp[i] != '.'; i++);	
	tempIp = &tempIp[i + 1];
	//cout << "third octet = "<< thirdOctet << endl;
	int fourthOctet = atoi(tempIp.c_str());
	//cout << "fourth octet = "<< fourthOctet << endl;
	if(firstOctet > 255 || secondOctet > 255 || thirdOctet > 255 || fourthOctet > 255) BigPartValue = true;
	}
	isCorrect = (!manyParts && !manyCharacters && !BigPartValue && onlyDigitsAndDots);
}

int main()
{
	string ip1;
	getline(cin, ip1);
	IPAddress a1(ip1);
	string ip2;
	getline(cin, ip2);
	IPAddressChecked a2(ip2);
	string ip3;
	getline(cin, ip3);
	IPAddressChecked a3(ip3);
	a1.Print();
	a2.Print();
	a3.Print();

	system("pause");
	return 0;
}