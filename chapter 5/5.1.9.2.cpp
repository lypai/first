#include <iostream>
using namespace std;

class AdHocSquare
{
	public:
	AdHocSquare(double _side)
	{
		side = _side;
	};
	void set_side(double _side)
	{
		side = _side;
	};
	double get_area()
	{
		return side*side;
	};
	private:
	double side;
};
class LazySquare
{
	public:
	LazySquare(double _side)
	{
		side = _side;
		area = _side * _side;
		side_changed = false;
	}
	void set_side(double _side)
	{
		side = _side;
		side_changed = true;
	};
	double get_area()
	{
		if(side_changed)
		{
			area = side * side;
			side_changed = false;
			return side_changed;
		}
		else
		{
			return area;
		}
	};
	private:
	double side;
	double area;
	bool side_changed;
};

int main()
{
	return 0;
}