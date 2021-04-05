#include <iostream>
// #include <vector>
#include <string>
using namespace std;

class Encoder
{
public:
	string encode(string &message, int key[])
	{
		string msg = message;
		int msgLength = message.size();
		int difference = (key[0] * key[1]) - msgLength;
		if (difference > 0)
			msg.resize(msgLength + difference, '_');
		// for (int i = 0; i < difference; i++)
		// 	msg += '_';

		string encodedMessage = "";
		for (int i = 0; i < key[1]; i++)
		{
			string aux;
			for (int j = 0; j < key[0]; j++)
			{
				aux += msg[i + (j * key[1])];
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
		string decodedMessage = "";
		for (int i = 0; i < key[0]; i++)
		{
			string aux;
			for (int j = 0; j < key[1]; j++)
			{
				// cout << msg[i + (key[0] * j)] << endl;
				aux += msg[i + (key[0] * j)];
			}
			decodedMessage += aux;
		}
		// delete extra characters;
		// cout << "preRefined : " << decodedMessage << endl;
		unsigned decodedMessageLength = decodedMessage.size();
		for (int i = 0; i < decodedMessageLength; i++)
		{
			if (decodedMessage[i] == '_')
			{
				for (int j = i; j < decodedMessage.size() - 1; j++)
				{
					decodedMessage[j] = decodedMessage[j + 1];
				}
				decodedMessage.resize(decodedMessage.size() - 1);
				decodedMessageLength--;
				i--;
			}
		}
		// cout << "postRefined : " << decodedMessage << endl;

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
	/*************************************************************************
	 * el producto de la llave, puede ser diferente a la longitud del string *
	 *************************************************************************/
	int key[2] = {5, 10};
	// int key[2] = {3, 6};
	Encoder encoder;
	// string a = encoder.generateMessage();
	Transmitter transmitter(key);
	Receiver receiver(key);
	string message = "hello world! how r u doing?";
	string encodedMessage = encoder.encode(message, transmitter.key);
	string decodedMessage = encoder.decode(encodedMessage, receiver.key);
	int strLength = message.size();
	cout << encodedMessage << endl;
	cout << decodedMessage << endl;

	return 0;
}
