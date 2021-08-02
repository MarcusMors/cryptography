#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str("Test string");
	// string str("012345");
	for (string::iterator it = str.end(); it != str.begin() - 1; --it)
		cout << *it;

	cout << '\n';

	return 0;
}
