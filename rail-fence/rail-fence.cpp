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
	// int arr[key];
	int flags[key - 2] = {0, 0, 0, 0};
	// cout << "interval: " << interval << endl;
	// cout << "size\t: " << size << endl;
	for (int i = 0; i < key; i++)
	{
		// cout << "<<<<<<<<<<<<  " << i << "  >>>>>>>>>>>" << endl;
		bool flag = false;
		string aux = "";
		int rowLimit = 1 + ((size - 1 - i) / interval);
		if ((i != 0 && i != key - 1) && size > interval - i)
		{
			rowLimit += 1 + ((size - 1 - (interval - i)) / interval);
			flag = true;
		}
		// cout << "rowLimit : " << rowLimit << endl;
		// arr[i] = rowLimit;
		for (int j = 0; j < rowLimit; j++)
		{
			if (flag && j % 2 == 1)
			{
				// int index = i + interval - (2 * i) * j;
				// int halfJ = j / 2;
				int index = i + (interval * (j / 2)) + interval - (2 * i);
				// int index = i + interval * halfJ - (2 * i) * j;
				// int index = i + (interval * (j / 2)) - (2 * i) * j;
				// int index = i + (interval * j / 2) + interval - (2 * i);
				char letter = message[index];
				// cout << "letter2 : " << letter << " index : " << index << endl;
				aux += letter;
			}
			else
			{
				int index;
				if (flag)
					index = i + (interval * j / 2);
				else
					index = i + (interval * j);
				const char letter = message[index];
				// cout << "letter : " << letter << " index : " << index << endl;
				aux += letter;
			}
		}
		// cout << "aux   : " << aux << endl;
		encodedMsg += aux;
	}
	// printArr(arr, key);
	return encodedMsg;
}
string cutString(string &str, int start, int end)
{
	string cutStr = "";
	for (int i = start; i < end; i++)
		cutStr += str[i];
	return cutStr;
}

string descipher(string &message, int key)
{
	string decodedMsg = "";
	string auxs[key];
	unsigned size = message.size();
	const int interval = (2 * (key - 1));
	unsigned counters[key];
	for (int i = 0; i < key; i++)
		counters[i] = 0;

	unsigned start = 0;
	unsigned end = 0;
	for (int i = 0; i < key; i++)
	{
		end += 1 + ((size - 1 - i) / interval);
		if ((i != 0) && (i != key))
		{
			end += 1 + (((size - i) - (interval - (2 * i))) / interval);
		}
		auxs[i] = cutString(message, start, end);
		decodedMsg += cutString(message, start, end);
		cout << "auxs[" << i << "] : " << auxs[i] << endl;
		start = end;
	}
	// unsigned counter = 0;
	// bool breaker = false;
	// while (counter < size)
	// {
	// 	decodedMsg += message[0];
	// 	counter++;
	// 	if (counter == size)
	// 		break;

	// 	for (int i = 1; i < key - 1; i++)
	// 	{
	// 		decodedMsg += message[i];
	// 		counter++;
	// 		if (counter == size)
	// 		{
	// 			breaker = true;
	// 			break;
	// 		}
	// 	}
	// 	if (breaker || (counter == size))
	// 		break;
	// 	decodedMsg += message[key - 1];
	// 	counter++;
	// 	if (counter == size)
	// 		break;
	// }

	// const int interval = (2 * (key - 1));
	// int flags[key - 2] = {0, 0, 0, 0};
	return decodedMsg;
}

int main()
{
	int key = 4;
	string msg = "Hello world! r u ok?";
	string cipheredMsg = cipher(msg, key);
	cout << "msg.size():" << msg.size() << endl;
	cout << cipheredMsg << endl;
	string descipheredMsg = descipher(msg, key);
	cout << descipheredMsg << endl;

	return 0;
}
