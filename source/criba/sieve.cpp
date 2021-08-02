#include <iostream>
#include <vector>
#include <math.h> /* sqrt */
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ myModule(ZZ &dividend, ZZ &divisor)
{
	const ZZ quotient = dividend / divisor;
	const ZZ remainder = dividend - (divisor * quotient);
	return remainder;
}

string debugger;
void squareRoot(ZZ number, ZZ &result, unsigned precision = 3)
{
	result = number >> 3;
	if (result != 0)
	{
		ZZ y = number / result;
		do
		{
			result += y;
			result = result >> 1;
			if (result == 0)
				break;
			y = number / result;
		} while (result - y > precision);
	}
}

bool isPrime(vector<ZZ> &primes, ZZ &number)
{
	ZZ top;
	squareRoot(number, top);
	for (vector<ZZ>::iterator it_ptr = primes.begin(); *it_ptr < top; it_ptr++)
		if (myModule(number, *it_ptr) == 0)
			return false;

	cout << number << ",";
	return true;
}

void eratosthenes_sieve(vector<ZZ> &primes, ZZ &end)
{
	// let's take 11 as the default start
	// 11 = 4n + 3
	// 11 = 6n + 5
	for (ZZ i = ZZ(11); i < end; i += 4)
	{
		// 4n + 3
		if (isPrime(primes, i))
			primes.push_back(i);
		// 4n + 1
		i += 2;
		if (isPrime(primes, i))
			primes.push_back(i);
	}
}

int main()
{
	ZZ start = ZZ(11);
	// ZZ end = conv<ZZ>("100");
	// ZZ end = conv<ZZ>("2793390");
	ZZ end = conv<ZZ>("65536");	  // 2^16
	ZZ end = conv<ZZ>("2793390"); // 2^16
	// ZZ end = conv<ZZ>("4294967296"); // 2^32
	// ZZ end = conv<ZZ>("18446744073709551616"); // 2^64
	// ZZ end = conv<ZZ>("27933904");			   // 2^128
	// ZZ end = conv<ZZ>("27933904");			   // 2^526
	vector<ZZ> primes = {ZZ(2), ZZ(3), ZZ(5), ZZ(7)};

	eratosthenes_sieve(primes, end);

	return 0;
}

// g++ -g -O2 -std=c++11 -pthread -march=native foo.cpp -o foo -lntl -lgmp -lm
