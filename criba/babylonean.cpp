#include <iostream>
#include <NTL/ZZ.h>

using namespace std;

long long babylonian_sqrt(long long number, unsigned precision)
{
	long long x = number / 10;
	long long y = number / x;
	do
	{
		x += y;
		x = long(x) >> 1;
		y = number / x;
	} while (x - y > precision);
	return x;
}

int main()
{
	cout << babylonian_sqrt(10000, 3) << endl;
	return 0;
}
