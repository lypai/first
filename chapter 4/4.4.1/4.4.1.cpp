#include <iostream> 
#include <string> 
#include <algorithm>

using namespace std;

int main(void) {
	int countLetters[26] = {0};
	string sentence; 
	getline(cin, sentence);
	transform(sentence.begin(), sentence.end(), sentence.begin(),::tolower);
	for(int i = 0; i < sentence.length(); i++)
	{
		char letter = sentence[i];
		for(int j = 0; j < 26; j++)
		{
			if(letter == 'a' + j)
				countLetters[j]++;
		}
	}

	bool isPangram = true;
	for(int j = 0; j < 26; j++)
	{
		if(countLetters[j] == 0) isPangram = false;
	}
	if(isPangram)
		cout << "Pangram" << endl;
	else
		cout << "Not pangram" << endl;
	for(int j = 0; j < 26; j++)
	{
		cout << char('a' + j) << "-" << countLetters[j] << endl;
	}
	system("pause");
	return 0;
}