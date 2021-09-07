#include <iostream>

using namespace std;

int module(int dividend, int divisor)
{
	int remainder = dividend - (divisor * (dividend / divisor));
	remainder += (remainder < 0) ? divisor : 0;
	return remainder;
}

int mcd(int a, int b)
{
	if (b == 0)
		return a;
	return mcd(b, module(a, b));
}

class Afin
{
private:
	int Euclid_extended(int a, int b)
	{
		// based in this explanation https://www.youtube.com/watch?v=D289EF58Yrw
		int cont = 0;
		int auxA = a, auxB = b;
		// non-recursive euclidian / doing euclidean division
		while (module(a, b) != 0)
		{
			int temp = b;
			b = module(a, b);
			a = temp;
			cont++;
		}
		cont = cont + 2;
		int g[cont] = {auxA, auxB};
		int y[cont];
		int u[cont] = {1, 0};
		int v[cont] = {0, 1};

		int i = 1;
		while (true)
		{
			y[i + 1] = g[i - 1] / g[i];
			g[i + 1] = g[i - 1] - (y[i + 1] * g[i]);
			u[i + 1] = u[i - 1] - (y[i + 1] * u[i]);
			v[i + 1] = v[i - 1] - (y[i + 1] * v[i]);
			if (g[i + 1] == 0)
				return module(u[i], g[1]);
			i++;
		}
	}

public:
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	const unsigned alphabetSize = alphabet.size();

	string cipher(string msg, int key[2])
	{
		string word;

		const unsigned size = msg.size();
		while (mcd(key[0], alphabetSize) != 1)
			key[0] = rand();

		cout << "key[0] = " << key[0] << endl;
		cout << "key[1] = " << key[1] << endl;

		for (int i = 0; i < size; i++)
		{
			const unsigned index = module((key[0] * (alphabet.find(msg[i]))) + key[1], alphabetSize);
			word.push_back(alphabet[index]);
		}
		return word;
	}
	string descipher(string msg, int key[2])
	{
		string word;

		const unsigned size = msg.size();
		key[0] = Euclid_extended(key[0], alphabetSize);
		for (int i = 0; i < size; ++i)
		{
			const unsigned index = module(key[0] * (alphabet.find(msg[i]) - key[1]), alphabetSize);
			word.push_back(alphabet[index]);
		}
		return word;
	}
};

class Transmitter
{
private:
	int key[2];

public:
	Transmitter(int iKey[2])
	{
		key[0] = iKey[0];
		key[1] = iKey[1];
	}
	string cipher(string message)
	{
		return Afin().cipher(message, key);
	}
};
class Receiver
{
private:
	int key[2];

public:
	Receiver(int iKey[2])
	{
		key[0] = iKey[0];
		key[1] = iKey[1];
	}
	string descipher(string message)
	{
		return Afin().descipher(message, key);
	}
};

// int main()
// {
// 	int key[2] = {mcd(301, Afin().alphabetSize), rand()};
// 	cout << Afin().alphabetSize << endl;
// 	string message = "clientsecret";

// 	Transmitter transmitter(key);
// 	Receiver receiver(key);
// 	string cipheredMsg = transmitter.cipher(message);
// 	cout << "ciphered message \t: " << cipheredMsg << endl;
// 	cout << endl;
// 	string descipheredMsg = receiver.descipher(cipheredMsg);
// 	cout << "desciphered message \t: " << descipheredMsg << endl;
// }
