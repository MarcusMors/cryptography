/**
 * @file cesar.cpp
 * @author Jose Vilca Campana <@marcusmors> (alivezeh@gmail.com)
 * @brief
 * @version DOC_VERSION_MAJOR.DOC_VERSION_MINOR
 * @date 2021-07-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief
 *
 * @param a
 * @param b
 * @return int
 */
int min(int a, int b)
{
	return a < b ? a : b;
}

/**
 * @brief
 *
 * @param strA
 * @param strB
 * @return unsigned
 */
unsigned levenshteinDistance(string t_strA, string t_strB)
{
	int sizeA = t_strA.size();
	int sizeB = t_strB.size();
	unsigned shortest = min(sizeA, sizeB);
	unsigned distance = abs(sizeA - sizeB);
	for (int i = 0; i < shortest; i++)
	{
		if (t_strA[i] != t_strB[i])
		{
			distance++;
		}
	}
	return distance;
}

class Cesar
{
private:
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	// string alphabet = "abcdefghijklmnopqrstuvwxyzABCDFGHIJKLMNOPQRSTUVWXYZ";
	// string alphabet = " abcdefghijklmnopqrstuvwxyzABCDFGHIJKLMNOPQRSTUVWXYZ";
	// string alphabet = "1 abcdefghijk2lmnopqrstu3vwxyz45ABCDFGH6IJKLMN7OP8QRSTUVW9XYZ";

public:
	void cipher(string &msg, int iKey)
	{
		int alphabetSize = alphabet.size();
		cout << "alphabetSize : " << alphabetSize << endl;
		int size = msg.size();
		int key = (iKey % alphabetSize);
		string ciphered = "";
		for (int i = 0; i < size; i++)
			for (int j = 0; j < alphabetSize; j++)
				if (msg[i] == alphabet[j])
				{
					ciphered += alphabet[(j + key) % alphabetSize];
					break;
				}
		msg = ciphered;
	}
	void descipher(string &msg, int iKey)
	{
		int alphabetSize = alphabet.size();
		int size = msg.size();
		cout << "alphabetSize : " << alphabetSize << endl;
		int key = (iKey % alphabetSize);
		string ciphered = "";
		for (int i = 0; i < size; i++)
			for (int j = 0; j < alphabetSize; j++)
				if (msg[i] == alphabet[j])
				{
					ciphered += alphabet[(alphabetSize + j - key) % alphabetSize];
					break;
				}
		msg = ciphered;
	}
	void cryptoAnalysis(string &msg) // desciph a message
	{
		int size = msg.size();
		int alphabetSize = alphabet.size();
		for (int key = 0; key < alphabetSize; key++)
		{
			string ciphered = "";
			for (int i = 0; i < size; i++)
				for (int j = 0; j < alphabetSize; j++)
					if (msg[i] == alphabet[j])
					{
						ciphered += alphabet[(alphabetSize + j - key) % alphabetSize];
						break;
					}
			cout << "key : " << key << endl;
			cout << ciphered << endl;
		}
		//* the other way
		// string directory = "dictionaries/";
		// int nFiles = 2;
		// string files[nFiles] = {
		// 	"english.txt",
		// 	"spanish.txt"};
		// for (int i = 0; i < nFiles; i++)
		// {
		// 	string path = directory + files[i];
		// 	ifstream dictionary;
		// 	dictionary.open(path, ios::in);
		// 	if (!dictionary)
		// 	{
		// 		cout << "Dictionary not found" << endl;
		// 		cout << "Do manual check" << endl;
		// 	}
		// 	else
		// 	{
		// 		string word;
		// 		while (true)
		// 		{
		// 			dictionary >> word;
		// 			if (dictionary.eof())
		// 				break;
		// 			cout << word << endl;
		// 		}
		// 		dictionary.close();
		// 	}
		// }
	}
};

class Receiver
{
private:
	int key;

public:
	Receiver(int iKey)
	{
		key = iKey;
	}
	void descipher(string &msg)
	{
		Cesar().descipher(msg, key);
	}
};
class Transmitter
{
private:
	int key;

public:
	Transmitter(int iKey)
	{
		key = iKey;
	}
	void cipher(string &msg)
	{
		Cesar().cipher(msg, key);
	}
};

int main()
{
	string msg;
	cout << "input message\t: ";
	getline(cin, msg);
	int key;
	cout << "input key\t: ";
	cin >> key;
	Receiver receiver(key);
	Transmitter transmitter(key);
	// string cipheredMsg = transmitter.cipher(msg);
	transmitter.cipher(msg);
	cout << "ciphered\t: " << msg << endl;
	cout << "crypto analysis" << endl;
	string interception = msg;
	Cesar().cryptoAnalysis(interception);
	receiver.descipher(msg);
	cout << "desciphered\t: " << msg << endl;

	return 0;
}
