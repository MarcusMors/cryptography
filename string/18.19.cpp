#include <iostream>

using namespace std;

int main()
{

	string message = "this is a string";
	int mid = message.size() / 2;
	message.insert(mid, "******");
	cout << message << endl;

	return 0;
}
