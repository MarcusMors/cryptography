#include <iostream>

using namespace std;

string cesar(string &alphabet, int key, string &msg)
{
	int alphabetSize = alphabet.size();
	string ciphered = "";
	for (int i = 0; i < msg.size(); i++)
		for (int j = 0; j < alphabetSize; j++)
			if (msg[i] == alphabet[j])
				ciphered += alphabet[abs(j + key) % alphabetSize];

	return ciphered;
}

class Receiver
{
private:
	int key;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

public:
	Receiver(int iKey)
	{
		key = iKey;
	}
	string descipher(string &msg)
	{
		cout << cesar(alphabet, key * -1, msg) << endl;
	}
};
class Transmitter
{
private:
	int key;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

public:
	Transmitter(int iKey)
	{
		key = iKey;
	}
	string cipher(string msg)
	{
		string message = msg;
		return cesar(alphabet, key, message);
	}
};

int main()
{
	int key = 2;
	Receiver receiver(key);
	Transmitter transmitter(key);
	string cipheredMsg = transmitter.cipher("hello");
	cout << "ciphered message" << endl;
	cout << cipheredMsg << endl;
	cout << "desciphered message" << endl;
	receiver.descipher(cipheredMsg);
	return 0;
}
