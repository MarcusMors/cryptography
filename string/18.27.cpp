#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str("7145");
	cout << str << endl;
	int cont = 0;

	// for (string::iterator it = str.begin(); it != str.end(); ++it)
	// {
	// 	int left = int(*it) - int('0');
	// 	cout << "left : " << left << endl;
	// 	for (string::iterator jt = it; jt != str.end() - cont; ++jt)
	// 	{
	// 		int right = int(*jt) - int('0');
	// 		cout << "\tright : " << right << endl;
	// 		if (left < right)
	// 		{
	// 			char aux = *it;
	// 			it = jt;
	// 			*jt = aux;
	// 			break;
	// 		}
	// 	}
	// 	cont++;
	// }

	for (string::iterator it = str.begin(); it != str.end(); ++it)
	{
		int left = int(*(it + cont)) - int('0');
		cout << "left : " << left << endl;
		for (string::iterator jt = it + 1; jt != str.end(); ++jt)
		{
			int right = int(*jt) - int('0');
			cout << "\tright : " << right << endl;
			if (left > right)
			{
				char aux = *it;
				*it = *jt;
				*jt = aux;
				cout << "\t\tl:" << *it << " - r:" << *jt << endl;
				cout << "\t\t" << str << endl;
			}
		}
		cout << "\t" << str << endl;
		cont++;
	}
	cout << str << endl;
	//this is a change
	return 0;
}
