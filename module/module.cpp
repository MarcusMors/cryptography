#include <iostream>

using namespace std;

void myModule(int a, int n)
{
	int q = a / n;
	int r = a - (q * n);
	cout << "q : " << q << endl;
	cout << "r : " << r << endl;
	if (r < 0)
	{
		q = (a / n) - 1;
		r = a - (q * n);
		cout << "q : " << q << endl;
		cout << "r : " << r << endl;
	}
}

int main()
{
	int a = -255;
	int n = 11;
	myModule(a, n);
	return 0;
}
