#include <iostream>
#include <string>
#include <iomanip> 
#include <sstream>
using namespace std;

class Point2D{
	public:
	Point2D(double x, double y);
	string toString();
	double toDouble();
	double GetX(){return x;};
	double GetY(){return y;};
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

class Line2D{
	public:
	Line2D(double slope, double y_intercept);
	Line2D(Point2D pointA, Point2D pointB);
	string toString();
	bool contains(Point2D point);

	private:
	double slope;
	double y_intercept;
};
bool Line2D::contains(Point2D point)
{
	if(abs(point.GetY() - (slope * point.GetX() + y_intercept)) < 0.000001) return true;
	return false;
}

Line2D::Line2D(double _slope, double _y_intercept)
{
	slope = _slope;
	y_intercept = _y_intercept;
}

Line2D::Line2D(Point2D pointA, Point2D pointB)
{
	slope = (pointA.GetY() - pointB.GetY())/(pointA.GetX() - pointB.GetX());
	y_intercept = pointB.GetY() - (pointA.GetY() - pointB.GetY())/(pointA.GetX() - pointB.GetX())*pointB.GetX();
}

string Line2D::toString()
{
	stringstream stream1;
	stream1 << fixed << setprecision(1) << slope;
	stringstream stream2;
	stream2 << fixed << setprecision(1) << y_intercept;
	string str = "y = " + stream1.str() + "x ";
	if(y_intercept < 0) str+= stream2.str();
	else str += "+ " + stream2.str(); 
	return str;
}

int main()
{
	double x1, x2, y1, y2, x3, y3;
	cin >> x1;
	cin >> y1;
	Point2D point1(x1, y1);
	cin >> x2;
	cin >> y2;
	Point2D point2(x2, y2);
	Line2D line(point1, point2);
	cin >> x3;
	cin >> y3;
	Point2D point3(x3, y3);
	if(line.contains(point3)) cout << "collinear" << endl;
	else cout << "not collinear" << endl;
	system("pause");
	return 0;
}