#include <iostream>
using namespace std;

int main(void)
{
	const int MAX_HEIGHT_SIZE = 9;
	const int MIN_HEIGHT_SIZE = 2;
	const int NUMBER_OF_PIRAMIDES = 3;
	int height;
	cout << "Enter pyramid's height(2-9): ";
	cin >> height;
	if (height <= MAX_HEIGHT_SIZE && height >= MIN_HEIGHT_SIZE)
	{
		int groundSideSize = height * 2 - 1;
		int position = height - 1;
		for(int i = 0; i < height; i++)
		{
			for (int n = 0; n < NUMBER_OF_PIRAMIDES; n++)
			{
				for(int j = 0; j < groundSideSize; j++)
				{
					if(j != position && j != (groundSideSize - position - 1) && i != (height - 1))
						cout << " ";
					else 
						cout << "*";				
				}
				cout << " ";
			}				
			position --;
			cout << endl;
		}		
	}
	else 
	{
		cout << "height size is invalid" << endl;
	}
	system("pause");
	return 0;
}