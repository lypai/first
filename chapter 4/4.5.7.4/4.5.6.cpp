#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Enter 2 words: ";
	string word1, word2;
	cin >> word1;
	cin >> word2;
	bool isAnagram = true;
	int lc1 = word1.size(), lc2 = word2.size();
	if (lc1 != lc2)
		isAnagram = false;
	else
	{
		for(int i = 0; i < word1.size(); i++)
		{
			if(word2.find(word1[i]) == string::npos)
				isAnagram = false;
		}
	}
	if(isAnagram) cout << "anagrams" << endl;
	else cout << "not anagrams" << endl;
	system("pause");
	return 0;
}