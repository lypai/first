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
	bool isGreaterThan(Fraction that);
	bool isLessThan(Fraction that);
	bool isEqual(Fraction that);

	private:
	int numerator;
	int denominator;
	void reduce();
};

bool Fraction::isEqual(Fraction that)
{
	Fraction copyCurrent(this->numerator, this->denominator);
	copyCurrent.reduce();
	Fraction copyThat = that;
	copyThat.reduce();
	if(copyCurrent.denominator == copyThat.denominator
		&& copyCurrent.numerator == copyThat.numerator) return true;
	return false;
}

bool Fraction::isLessThan(Fraction that)
{
	Fraction copyCurrent(this->numerator, this->denominator);
	copyCurrent.reduce();
	Fraction copyThat = that;
	copyThat.reduce();
	if((copyCurrent.numerator * 1. /copyCurrent.denominator)
		< (copyThat.numerator * 1. / copyThat.denominator)) return true;
	return false;
}
bool Fraction::isGreaterThan(Fraction that)
{
	return !isLessThan(that);
}


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
	if(fraction1.isEqual(fraction2))
		cout <<  fraction1.toString() + " = " + fraction2.toString() << endl;
	else if(fraction1.isLessThan(fraction2))
		cout <<  fraction1.toString() + " < " + fraction2.toString() << endl;
	else if(fraction1.isGreaterThan(fraction2))
		cout <<  fraction1.toString() + " > " + fraction2.toString() << endl;
	
	system("pause");
	return 0;
}