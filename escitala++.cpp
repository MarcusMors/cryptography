#include <iostream>
#include <vector>
// #include <string>
using namespace std;

class Encoder
{
public:
	// int key;
	string encode(string &message, int key[])
	{
		string msg = message;
		int msgLength = message.size();
		int lengthCounter = 0;
		string encodedMessage = "";
		for (int i = 0; i < key[1]; i++)
		{
			string aux;
			for (int j = 0; j < key[0]; j++)
			{
				lengthCounter++;
				if (lengthCounter > msgLength)
				{
					aux += " ";
				}
				else
				{
					aux += msg[i + (j * key[1])];
				}
			}
			encodedMessage += aux;
		}
		// delete &message;
		return encodedMessage;
	};
	string decode(string &message, int key[])
	{
		string msg = message;
		int msgLength = message.size();
		int lengthCounter = 0;
		string decodedMessage = "";
		for (int i = 0; i < key[0]; i++)
		{
			string aux;
			for (int j = 0; j < key[1]; j++)
			{
				lengthCounter++;
				if (lengthCounter > msgLength)
				{
					aux += " ";
				}
				else
				{
					aux += msg[i + (key[0] * j)];
				}
			}
			decodedMessage += aux;
		}
		// delete &message;
		return decodedMessage;
	};
};

class Receiver
{
public:
	int key[2];
	Receiver(int iKey[])
	{
		key[0] = iKey[0];
		key[1] = iKey[1];
	}
};

class Transmitter
{
public:
	int key[2];
	Transmitter(int iKey[])
	{
		key[0] = iKey[0];
		key[1] = iKey[1];
	}
	// string generateMessage()
	// {
	// 	string *msg_ptr;
	// 	string msg;
	// 	Encoder encoder;
	// 	cin >> msg;
	// 	encoder.encode(msg, key);
	// }
};

int main()
{
	int key[2] = {5, 6};
	// int key[2] = {3, 4};
	Encoder encoder;
	// string a = encoder.generateMessage();
	Transmitter transmitter(key);
	Receiver receiver(key);
	string message = "hello world! how are you doing?";
	// string message = "hello world!";
	string encodedMessage = encoder.encode(message, transmitter.key);
	string decodedMessage = encoder.decode(encodedMessage, receiver.key);
	int strLength = message.size();
	cout << encodedMessage << endl;
	cout << decodedMessage << endl;

	return 0;
}
