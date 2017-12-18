#include <iostream>
using namespace std;

int main(void)
{
	cout << "Enter the number of courses taken by the student: ";
	int coursesNumber;
	cin >> coursesNumber;
	int **ptrarr = new int *[coursesNumber]; 
	int *numbersOfGrades= new int[coursesNumber];
	double* finals = new double[coursesNumber];
	for(int i = 0; i < coursesNumber; i++)
	{
		cout << "Enter number of grades received during course " << i + 1 << " and grades: ";
		int gradesNumber;
		int grade;
		cin >> gradesNumber;
		numbersOfGrades[i] = gradesNumber;
		ptrarr[i] = new int[gradesNumber];
		for(int n = 0; n < gradesNumber; n++)
		{
			cin >> grade;
			ptrarr[i][n] = grade;
		}
	}
	cout << endl;
	for(int i = 0; i < coursesNumber; i++)
	{
		finals[i] = 0;
		for(int j = 0; j < numbersOfGrades[i]; j++)
		{
			finals[i] += ptrarr[i][j];
		}
		finals[i] /= numbersOfGrades[i];
		cout.precision(2);
		cout << "Course " << i + 1 << ": final " << fixed << finals[i] << ", grades: ";
		for(int j = 0; j < numbersOfGrades[i]; j++)
		{
			cout << ptrarr[i][j] << " ";
		}
		cout << endl;
	}

	double overalFinal = 0;
	for(int i = 0; i < coursesNumber; i++)
	{
		overalFinal += finals[i];
	}
	overalFinal /= coursesNumber;
	cout << "Overal final " << overalFinal << endl;

	for(int i = 0; i < coursesNumber; i++)
		delete[] ptrarr[i];
	delete[] numbersOfGrades;
	delete[] finals;
	system("pause");
	return 0;
}