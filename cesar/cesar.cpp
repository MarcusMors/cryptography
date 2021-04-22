#include <iostream>

using namespace std;

void cesar(string &alphabet, int key, string &msg)
{
	int alphabetSize = alphabet.size();
	string ciphered = "";
	for (int i = 0; i < msg.size(); i++)
		for (int j = 0; j < alphabetSize; j++)
			if (msg[i] == alphabet[j])
				ciphered += alphabet[abs(j + key) % alphabetSize];

	msg = ciphered;
}

class Receiver
{
private:
	int key;
	string alphabet;

public:
	Receiver(int iKey, string iAlphabet)
	{
		key = iKey;
		alphabet = iAlphabet;
	}
	void descipher(string &msg)
	{
		cesar(alphabet, key * -1, msg);
	}
};
class Transmitter
{
private:
	int key;
	string alphabet;

public:
	Transmitter(int iKey, string iAlphabet)
	{
		alphabet = iAlphabet;
		key = iKey;
	}
	void cipher(string &msg)
	{
		cesar(alphabet, key, msg);
	}
};

int main()
{
	// string alphabet = "abcdefghijklmnopqrstuvwxyz";
	// string alphabet = "abcdefghijklmnopqrstuvwxyzABCDFGHIJKLMNOPQRSTUVWXYZ";
	// string alphabet = " abcdefghijklmnopqrstuvwxyzABCDFGHIJKLMNOPQRSTUVWXYZ";
	string alphabet = "1 abcdefghijk2lmnopqrstu3vwxyz45ABCDFGH6IJKLMN7OP8QRSTUVW9XYZ";
	string msg;
	cout << "input message: ";
	getline(cin, msg);
	int key;
	cout << "input key    : ";
	cin >> key;
	Receiver receiver(key, alphabet);
	Transmitter transmitter(key, alphabet);
	// string cipheredMsg = transmitter.cipher(msg);
	transmitter.cipher(msg);
	cout << "ciphered message" << endl;
	cout << msg << endl;
	// cout << "crypto analysis" << endl;
	// cout << cryptoAnalysis(msg) << endl;
	receiver.descipher(msg);
	cout << "desciphered message" << endl;
	cout << msg << endl;
	return 0;
}
