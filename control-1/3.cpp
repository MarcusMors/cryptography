#include <iostream>

using namespace std;

int main()
{
	// cout << "START" << endl;
	// long long number = 1234;
	// long long number = 1234;
	long long number = 548365842358;
	// cout << "number : " << number << endl;
	string answer = "";
	string strAux = "";
	long long aux = number % 10;
	number = number / 10;
	while (number > 0)
	{
		strAux += char(aux + int('0'));
		aux = number % 10;
		number = number / 10;
	}
	strAux += char(aux + int('0'));
	for (int i = strAux.size() - 1; i >= 0; i--)
	{
		answer += strAux[i];
	}
	cout << answer << endl;
	return 0;
}
