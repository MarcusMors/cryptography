#include <iostream>

using namespace std;

int mcd(int a, int b)
{
	if (b == 0)
		return a;
	return mcd(b, a % b);
}

int diophantic(int a, int b, int &x, int &y)
{
}

int main()
{
	int a = 250;
	int b = 111;
	int c = mcd(a, b);
	cout << a << "x + " << b << "y = " << c << endl;
	int x;
	int y;
	diophantic(a, b, x, y);
	cout << a << "(" << x << ") + " << b << "(" << y << ") = " << c << endl;

	return 0;
}
