#include <iostream> 
#include <string> 
#include <regex>

using namespace std;

int main(void) {
	regex isDigit("[1-9]");
	string firstOctet, secondOctet, thirdOctet, fourthOctet;
	cout << "Enter ip: ";
	string ip;
	cin >> ip;
	bool manyCharacters = false, manyParts = false,
		onlyDigitsAndDots = true, BigPartValue = false, incorrectNumber = false;
	int lastDotPosition = 0, dotCount = 0;

	string dotIp = ip;
	for(unsigned int i = 0; i < ip.length(); i++)
	{

		if(ip.substr(i, 1) == ".") 
			dotCount++;	
		if((ip.substr(i, 1) != ".") && (! regex_match(ip.substr(i, 1), isDigit)))
			onlyDigitsAndDots = false;
	}
	
	if(dotCount > 3) manyParts = true;
	if(dotCount != 3) incorrectNumber = true;
	if(!manyParts && onlyDigitsAndDots){
		firstOctet = ip.substr(0, ip.find("."));
		ip = ip.substr(ip.find(".") + 1);
		secondOctet = ip.substr(0, ip.find("."));
		ip = ip.substr(ip.find(".") + 1);
		thirdOctet  = ip.substr(0, ip.find("."));
		ip = ip.substr(ip.find(".") + 1);
		fourthOctet = ip.substr(0, ip.find("."));
		if(firstOctet.length() > 3 || secondOctet.length() > 3 ||
			thirdOctet.length() > 3 || fourthOctet.length() > 3) manyCharacters = true;
	}
	if(!manyParts && !manyCharacters && onlyDigitsAndDots){
		if(atoi(firstOctet.c_str()) > 255 || atoi(secondOctet.c_str()) > 255 ||
			atoi(thirdOctet.c_str()) > 255 || atoi(fourthOctet.c_str()) > 255) 
			BigPartValue = true;
	}
	if(!onlyDigitsAndDots) cout << "Only digits and dots allowed" << endl;
	else if(manyParts) cout << "Too many parts" << endl;
	else if(incorrectNumber) cout << "Incorrect parts count" << endl; 
	else if(manyCharacters) cout << "Too many characters in a part" << endl;
	else if(BigPartValue) cout << "Too big a value of a part" << endl;
	else cout << "Correct IP" << endl;
	system("pause");
	return 0;
}