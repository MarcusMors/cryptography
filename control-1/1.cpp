#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	string text;
	// cin >> text;
	// cout << "size " << text.size() << endl;
	getline(cin, text);
	int size = text.size();
	int chunkSize;
	cin >> chunkSize;
	string aux = "";
	string chunks = "";
	vector<string> vec_str;

	for (int i = 0; i < size; i += chunkSize)
	{
		for (int j = i; j < i + chunkSize; j++)
		{
			if (j >= size)
			{
				aux += 'X';
				chunks += 'X';
			}
			else
			{
				chunks += text[j];
				aux += text[j];
			}
		}
		cout << aux << endl;
		vec_str.push_back(aux);
		chunks += '*';
		aux = "";
	}
	cout << chunks << endl;
	chunks.pop_back();
	for (int i = 0; i < vec_str.size(); i++)
	{
		cout << vec_str[i] << " , ";
	}
	cout << endl;
	return 0;
}
