#include <iostream>
using namespace std;

class DrawBase
{
	public:
	virtual void Draw();
};
void DrawBase::Draw()
{
	cout << "Base draw" << endl;
}

class SlashDraw: public DrawBase
{
	public:
	void Draw();
};
void SlashDraw::Draw()
{
	cout << " /\\" << endl;
	cout << "//\\\\" << endl;
}

class PlusDraw: public DrawBase
{
	public:
	void Draw();
};
void PlusDraw::Draw()
{
	cout << " /\\" << endl;
	cout << "/++\\" << endl;
}
class AsteriskDraw: public DrawBase
{
	public:
	void Draw();
};
void AsteriskDraw::Draw()
{
	cout << " /\\" << endl;
	cout << "/**\\" << endl;
}
int main()
{
	DrawBase** pbase = new DrawBase*[3];
	pbase[0] = new SlashDraw();
	pbase[1] = new AsteriskDraw();
	pbase[2] = new PlusDraw();
	for(int i = 0; i < 3; i++)
	{
		cout << "Drawing " << (i + 1) << ":" << endl;
		pbase[i]->Draw();
	}
	system("pause");
	return 0;
}