#include <iostream>

using namespace std;

void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " , ";
	cout << endl;
}

string cipher(string &message, int key)
{
	unsigned size = message.size();
	string encodedMsg = "";
	const int interval = (2 * (key - 1));
	int arr[key];
	int flags[key - 2] = {0, 0, 0, 0};
	cout << "interval: " << interval << endl;
	cout << "size\t: " << size << endl;
	for (int i = 0; i < key; i++)
	{
		cout << "<<<<<<<<<<<<  " << i << "  >>>>>>>>>>>" << endl;
		bool flag = false;
		string aux = "";
		int rowLimit = 1 + ((size - 1 - i) / interval);
		// cout << "1 + (size-i)/interval : 1+(" << size << "-" << i << ""
		// 	 << ")/" << interval << endl;
		// int rowLimit = 1;
		if ((i != 0 && i != key - 1) && size > interval - i)
		{
			rowLimit += 1 + ((size - 1 - (interval - i)) / interval);
			flag = true;
			flags[i] = true;
		}
		cout << "rowLimit : " << rowLimit << endl;
		arr[i] = rowLimit;
		for (int j = 0; j < rowLimit; j++)
		{
			cout << "j:" << j << endl;
			if (flag && j % 2 == 1)
			{
				// int index = i + interval - (2 * i) * j;
				// int halfJ = j / 2;
				int index = i + (interval * (j / 2)) + interval - (2 * i);
				// int index = i + interval * halfJ - (2 * i) * j;
				// int index = i + (interval * (j / 2)) - (2 * i) * j;
				// int index = i + (interval * j / 2) + interval - (2 * i);
				char letter = message[index];
				cout << "letter2 : " << letter << " index : " << index << endl;
				aux += letter;

				// if (((interval * j) - i) < size)
				// {
				// }
			}
			else
			{
				int index;
				if (flag)
				{
					index = i + (interval * j / 2);
				}
				else
				{
					index = i + (interval * j);
				}
				const char letter = message[index];
				cout << "letter : " << letter << " index : " << index << endl;
				aux += letter;
			}
		}
		cout << "aux   : " << aux << endl;
		encodedMsg += aux;
	}
	printArr(arr, key);
	return encodedMsg;
}
// string descipher(string &message, int key)
// {
// }

int main()
{
	int key = 4;
	string msg = "Hello world!";
	string cipheredMsg = cipher(msg, key);
	cout << 12 / 6 << endl;
	cout << cipheredMsg << endl;
	// string descipheredMsg = descipher(msg, key);
	return 0;
}
