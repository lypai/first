#include <iostream>
using namespace std;

class Position
{
public:
	int x, y;
	Position(int _x, int _y);
};
Position::Position(int _x, int _y)
{
	x = _x;
	y = _y;
}
class Piece
{
	public:
	virtual bool Check(Position p1, Position p2);
};
bool Piece::Check(Position p1, Position p2)
{
	return true;
}
class Man : public Piece
{
	bool Check(Position p1, Position p2);
};
bool Man::Check(Position p1, Position p2)
{
	if(((abs(p1.x - p2.x) == 1) && ((p2.y - p1.y) == 1)))
		return true;
	return false;
}

class King : public Piece
{
	bool Check(Position p1, Position p2);
};
bool King::Check(Position p1, Position p2)
{
	if(abs(p1.x - p2.x) == abs(p2.y - p1.y))
		return true;
	return false;
}

int main()
{
	Piece * pman1 = new Man();
	Piece * pking = new King();
	Piece * pman2 = new Man();
	cout << pman1->Check(Position(2, 1), Position(3, 2)) << endl;
	cout << pking->Check(Position(2, 1), Position(4, 3)) << endl;
	cout << pman2->Check(Position(2, 1), Position(4, 3)) << endl;
	system("pause");
	return 0;
}