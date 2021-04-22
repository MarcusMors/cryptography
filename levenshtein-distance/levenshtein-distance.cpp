#include <iostream>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

unsigned levenshteinDistance(string strA, string strB)
{
	int sizeA = strA.size();
	int sizeB = strB.size();
	int shortest = min(sizeA, sizeB);
	int distance = abs(sizeA - sizeB);
	for (int i = 0; i < shortest; i++)
	{
		if (strA[i] != strB[i])
		{
			distance++;
		}
	}
	return distance;
}

int main()
{
	string strA = "identity";
	string strB = "identify";
	int distance = levenshteinDistance(strA, strB);

	cout << distance << endl;
	return 0;
}
