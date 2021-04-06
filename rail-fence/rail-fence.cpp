#include <iostream>

using namespace std;

string cipher(string &message, int key)
{
	unsigned size = message.size();
	string encodedMsg = "";
	const int interval = (2 * (key - 1));
	for (int i = 0; i < key; i++)
	{
		bool flag = false;
		string aux = "";
		int rowLimit = 1 + ((size - 1 - i) / interval);
		if ((i != 0 && i != key - 1) && size > interval - i)
		{
			rowLimit += 1 + ((size - 1 - (interval - i)) / interval);
			flag = true;
		}
		for (int j = 0; j < rowLimit; j++)
		{
			if (flag && (j % 2 == 1))
				aux += message[i + (interval * (j / 2)) + interval - (2 * i)];
			else
			{
				if (flag)
					aux += message[i + (interval * j / 2)];
				else
					aux += message[i + (interval * j)];
			}
		}
		encodedMsg += aux;
	}
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
	const int interval = (2 * (key - 1));
	unsigned size = message.size();

	unsigned start = 0;
	unsigned end = 0;
	for (int i = 0; i < key; i++)
	{
		end += 1 + ((size - 1 - i) / interval);
		if ((i != 0) && (i != key))
			end += 1 + (((size - 1 - i) - (interval - (2 * i))) / interval);
		auxs[i] = cutString(message, start, end);
		start = end;
	}

	unsigned counter = 0;
	bool breaker = false;
	int counters[key];
	for (int i = 0; i < key; i++)
		counters[i] = 0;

	while (counter < size + 1)
	{
		decodedMsg += auxs[0][counters[0]];
		counters[0]++;
		counter++;
		if (counter == size)
			break;
		for (int i = 1; i < key - 1; i++)
		{
			decodedMsg += auxs[i][counters[i]];
			counters[i]++;
			counter++;
			if (counter == size)
			{
				breaker = true;
				break;
			}
		}

		if (breaker || (counter == size))
			break;
		decodedMsg += auxs[key - 1][counters[key - 1]];
		counters[key - 1]++;
		counter++;
		if (counter == size)
			break;

		for (int i = key - 2; i > 0; i--)
		{
			decodedMsg += auxs[i][counters[i]];
			counters[i]++;
			counter++;
			if (counter == size)
			{
				breaker = true;
				break;
			}
		}

		if (breaker || (counter == size))
			break;
	}
	return decodedMsg;
}
class Receiver
{
public:
	int key;
	Receiver(int iKey)
	{
		key = iKey;
	}
	void receiveMessage(string &message)
	{
		cout << cipher(message, key) << endl;
	}
};

class Transmitter
{
public:
	int key;
	Transmitter(int iKey)
	{
		key = iKey;
	}
	string generateMessage(string message)
	{
		return cipher(message, key);
	}
};
int main()
{
	int key = 4;
	Transmitter transmitter(key);
	Receiver receiver(key);
	// string cipheredMsg = transmitter.generateMessage("How are you doing since the 2020 pandemy?");
	string cipheredMsg = transmitter.generateMessage("Hello world!");
	cout << cipheredMsg << endl;
	receiver.receiveMessage(cipheredMsg);

	return 0;
}
