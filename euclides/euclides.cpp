#include <iostream>

using namespace std;

int mcd(int a, int b)
{
	if (b == 0)
		return a;
	return mcd(b, a % b);
}

int main()
{
	int a = 250;
	int b = 125;
	cout << mcd(a, b) << endl;
	return 0;
}
