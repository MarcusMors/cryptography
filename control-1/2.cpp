#include <iostream>

using namespace std;

long long power(long long base, long long pow)
{
	if (pow == 0)
		return 1;
	long long aux = 1;
	for (int i = 0; i < pow - 1; i++)
		aux = aux * base;
	return aux;
}

int main()
{

	// string str = "1035";
	// string str = "15325";
	string str = "548365842358";
	int size = str.size();
	long long aux;
	long long cont = 0;
	for (int i = 0; i < size; i++)
	{
		aux = int(str[i]) - int('0');
		aux = aux * power(10, (size - i));
		cont += aux;
	}
	cout << cont << endl;
	return 0;
}
