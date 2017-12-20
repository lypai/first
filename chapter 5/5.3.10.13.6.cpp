#include <iostream>
#include <string>
using namespace std;
class Fraction{
	public:
	Fraction(int numerator, int denominator);
	string toString();
	double toDouble();
	private:
	int numerator;
	int denominator;
};

Fraction::Fraction(int _numerator, int _denominator)
{
	numerator = _numerator;
	if(_denominator != 0) denominator = _denominator;
	else 
	{
		cout << "Denominator cannot be zero" << endl;
		denominator = 1;
	}
}

string Fraction::toString()
{
	string result = "";
	int copyDenominator = denominator, copyNumerator = numerator;
	if(copyDenominator < 0 || copyNumerator < 0)
	{
		result += "-";
		if(copyNumerator < 0) copyNumerator *= (-1);
		if(copyDenominator < 0) copyDenominator *= (-1);
	}
	if(copyNumerator/copyDenominator > 0) 
	{
		result += (to_string(copyNumerator/copyDenominator) + " ");
		copyNumerator = copyNumerator % copyDenominator;
	}
	if(copyNumerator!= 0)
	{
		result += (to_string(copyNumerator) + "/" + to_string(copyDenominator));
	}
	return result;
}

double Fraction::toDouble()
{ return (numerator*1. / denominator);
}

int main(void) {
	int num, den;
	scanf("%d / %d", &num, &den);
	cout << "num = " << num << " den = " << den << endl;
	Fraction fraction(num, den);
	cout.precision(2);
	cout << fraction.toString() << " is " << fixed << fraction.toDouble() << " in decimal" << endl;
	system("pause");
	return 0;
}