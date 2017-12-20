#include <iostream>
#include <string>
using namespace std;

class Point2D{
	public:
	Point2D(double x, double y);
	string toString();
	double toDouble();
	// ...
	double distanceTo(Point2D that);
	private:
	double x;
	double y;
};

Point2D::Point2D(double _x, double _y)
{
	x = _x;
	y = _y;
}

string Point2D::toString()
{
	string result = "x = " + to_string(x) + "; y = " + to_string(y);
	return result;
}

double Point2D::distanceTo(Point2D that)
{
	return sqrt((x-that.x)*(x-that.x) + (y - that.y)*(y - that.y));
}

int main()
{
	double x1, x2, y1, y2;
	cin >> x1;
	cin >> y1;
	Point2D point1(x1, y1);
	cin >> x2;
	cin >> y2;
	Point2D point2(x2, y2);
	cout << point1.distanceTo(point2) << endl;
	system("pause");
	return 0;
}