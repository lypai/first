#include <iostream>
#include <string>
using namespace std;
class Square
{
	public:	Square(double side);
	void set_side(double _side)
			{
				if(_side > 0)
				{
					side = _side;
					area = _side * _side;
				}
			}
	void print()
	{
		cout << "Square: side=" << side << " area=" << area << endl;
	}
	private: double side;
	private: double area;

	// Your code here
};
Square::Square(double side)
{
	this->side = side;
	this->area = side * side;
}
int main()
{
	Square s(4);
	s.print();
	s.set_side(2.0);	
	s.print();
	s.set_side(-33.0);	
	s.print();
	system("pause");
	return 0;
}