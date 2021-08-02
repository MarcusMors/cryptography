#include <iostream>
#include <string>
using namespace std;

class Encoder
{
public:
	string encode(string &message, int key[])
	{
		string msg = message;
		unsigned msgLength = message.size();

		//Add characters to match the key
		int difference = (key[0] * key[1]) - msgLength;
		if (difference > 0)
			msg.resize(msgLength + difference, '_');

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
		return encodedMessage;
	};

	string decode(string &message, int key[])
	{
		string msg = message;
		string decodedMessage = "";
		for (int i = 0; i < key[0]; i++)
		{
			string aux;
			for (int j = 0; j < key[1]; j++)
				aux += msg[i + (key[0] * j)];
			decodedMessage += aux;
		}
		// delete extra characters;
		unsigned decodedMessageLength = decodedMessage.size();
		for (int i = 0; i < decodedMessageLength; i++)
			if (decodedMessage[i] == '_')
			{
				for (int j = i; j < decodedMessage.size() - 1; j++)
					decodedMessage[j] = decodedMessage[j + 1];
				decodedMessage.resize(decodedMessage.size() - 1);
				decodedMessageLength--;
				i--;
			}

		return decodedMessage;
	};
};
Encoder encoder;

class Receiver
{
public:
	int key[2];
	Receiver(int iKey[])
	{
		key[0] = iKey[0];
		key[1] = iKey[1];
	}
	void receiveMessage(string &message)
	{
		cout << encoder.decode(message, key) << endl;
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
	string generateMessage(string message)
	{
		return encoder.encode(message, key);
	}
};

int main()
{
	/*************************************************************************
	 * el producto de la llave, puede ser diferente a la longitud del string *
	 *************************************************************************/
	int key[2] = {5, 10};
	// int key[2] = {3, 6};
	Transmitter transmitter(key);
	Receiver receiver(key);
	string encodedMessage = transmitter.generateMessage("hello world! how are you doing?");
	cout << encodedMessage << endl;
	receiver.receiveMessage(encodedMessage);

	return 0;
}
