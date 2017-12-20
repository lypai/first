#include <iostream>
#include <string>
using namespace std;
class Fraction{
	public:
	Fraction(int numerator, int denominator);
	string toString();
	double toDouble();
	Fraction plus(Fraction that);
	Fraction minus(Fraction that);
	Fraction times(Fraction that);
	Fraction by(Fraction that);

	private:
	int numerator;
	int denominator;
	void reduce();
};

Fraction Fraction::times(Fraction that)
{
	int num = this->numerator * that.numerator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;
}

Fraction Fraction::by(Fraction that)
{
	int num = this->numerator * that.denominator;
	int den = this->denominator * that.numerator;
	Fraction result(num, den);
	result.reduce();
	return result;
}

Fraction Fraction::plus(Fraction that)
{
	int num = this->numerator * that.denominator + this->denominator * that.numerator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;
}

Fraction Fraction::minus(Fraction that)
{
	int num = this->numerator * that.denominator - this->denominator * that.numerator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;
}

void Fraction::reduce()
{
	int copyDenominator, copyNumerator;
	if(denominator < 0) copyDenominator = denominator * (-1);
	else copyDenominator = denominator;
	if(numerator < 0) copyNumerator = numerator * (-1);
	else copyNumerator = numerator;

	while(copyDenominator != 0 && copyNumerator != 0)
	{
		if(copyNumerator > copyDenominator) copyNumerator %= copyDenominator;
		else copyDenominator %= copyNumerator;
	}
	int maxCommonDivision = copyDenominator + copyNumerator;
	denominator /= maxCommonDivision;
	numerator /= maxCommonDivision;
}

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
	int num1, den1;
	cout << "Enter first fraction: ";
	scanf("%d / %d", &num1, &den1);
	Fraction fraction1(num1, den1);
	int num2, den2;
	cout << "Enter second fraction: ";
	scanf("%d / %d", &num2, &den2);
	Fraction fraction2(num2, den2);
	cout << fraction1.toString() + " + " + fraction2.toString() << " = " << fraction1.plus(fraction2).toString() << endl;
	cout << fraction1.toString() + " - " + fraction2.toString() << " = " << fraction1.minus(fraction2).toString() << endl;
	cout << fraction1.toString() + " * " + fraction2.toString() << " = " << fraction1.times(fraction2).toString() << endl;
	cout << fraction1.toString() + " / " + fraction2.toString() << " = " << fraction1.by(fraction2).toString() << endl;

	system("pause");
	return 0;
}