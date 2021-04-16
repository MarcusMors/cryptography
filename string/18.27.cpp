#include <iostream>
#include <string>

using namespace std;
void sort(string strs[], const int len, bool (*compare)(string, string))
{
	int minOrMax;
	for (int i = 0; i < len - 1; i++)
	{
		minOrMax = i;
		for (int index = i + 1; index < len; index++)
			if (!(*compare)(strs[minOrMax], strs[index]))
				minOrMax = index;
		strs[minOrMax].swap(strs[i]);
	}
}
bool ascendant(string a, string b)
{
	return a[0] < b[0];
}
bool descendant(string a, string b)
{
	return a[0] > b[0];
}

void printStrs(string strs[], int n, int &cont)
{
	for (cont = 0; cont < n; cont++)
		cout << strs[cont] << " ";
	cout << endl;
}

int main()
{
	const int arrLength = 10;
	int order = 0;
	int cont;
	string strs[arrLength] = {"palimpsesto", "diadema", "duopolio", "hambre", "androgino", "marcelo", "agua", "fluorescente", "cena", "larimar"};
	cout << "palabra antes" << endl;
	printStrs(strs, arrLength, cont);

	if (order == 1)
		sort(strs, arrLength, ascendant);
	else
		sort(strs, arrLength, descendant);

	printStrs(strs, arrLength, cont);

	return 0;
}
