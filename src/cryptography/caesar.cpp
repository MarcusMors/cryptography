#include <fstream>
#include <vector>
// user made public libs
#include <cryptography/caesar.hpp>
#include <operations/module.hpp>
// user made libs
#include "../constants/alphabets.hpp"
#include "../constants/letter_frequency.hpp"

using namespace std;
using namespace operations;

void Caesar::cipher(string_view &t_msg, const int &t_key)
{
	const int msg_size = t_msg.size() - 1;
	const int key = mod(t_key, alphabet.size());

	for (int i = 0; i < msg_size; i++)
	{
		for (int j = 0; j < alphabet.size(); j++)
		{
			if (t_msg[i] == alphabet[j])
			{
				ciphered[i] = alphabet[mod((j + key), alphabet.size())];
				break;
			}
		}
	}
	for (unsigned i = 0; i < msg_size; i++)
	{
		t_msg[i] = ciphered[i];
	}
	cout << ciphered << endl;
}

void Caesar::descipher(string_view t_msg, const int &t_key)
{
	const int msg_size = t_msg.size() - 1;
	const int key = mod(t_key, alphabet.size());

	char ciphered[msg_size];
	for (int i = 0; i < msg_size; i++)
	{
		for (int j = 0; j < alphabet.size(); j++)
		{
			if (t_msg[i] == alphabet[j])
			{
				ciphered[i] = alphabet[mod((j + alphabet.size() - key), alphabet.size())];
				break;
			}
		}
	}
	for (unsigned i = 0; i < msg_size; i++)
	{
		t_msg[i] = ciphered[i];
	}
	cout << ciphered << endl;
}

bool is_not_in(char t_wanted, string t_str)
{
	for (size_t i = 0; i < t_str.size(); i++)
	{
		if (t_wanted == t_str[i])
		{
			return false;
		}
	}
	return true;
}

void Caesar::crypto_analysis(char t_msg[]) // desciph a message
{
	int msg_size = sizeof(t_msg) - 1;

	vector<int> frequency[2];
	string letters = "";
	for (int i = 0; i < msg_size; i++)
	{
		bool flag = false;
		for (size_t j = 0; j < frequency[0].size(); j++)
		{
			if (t_msg[i] == char(frequency[1][j]))
			{
				frequency[0][j] += 1;
				flag = true;
				break;
			}
		}
		if (flag)
		{
			frequency[0].push_back(1);
			frequency[1].push_back(int(t_msg[i]));
		}
	}

	int old_greatest = 100000;
	for (int i = 0; i < sizeof(letter_frequency::english) - 1; i++)
	{
		int greatest = -10000;
		int index;
		char copy[msg_size];
		for (int j = 0; j < msg_size; j++)
		{
			copy[j] = t_msg[j];
		}

		for (size_t j = 0; j < frequency[0].size(); j++)
		{
			if (frequency[0][j] > greatest && frequency[0][j] < old_greatest)
			{
				greatest = frequency[0][j];
				index = j;
			}
		}
		old_greatest = greatest;

		for (int j = 0; j < alphabet.size(); j++)
		{
			if (char(frequency[1][index]) == alphabet[j])
			{
				descipher(copy, index);
				break;
			}
		}
	}
}

// int main()
// {
// 	string msg;
// 	cout << "input message\t: ";
// 	getline(cin, msg);
// 	int key;
// 	cout << "input key\t: ";
// 	cin >> key;
// 	Receiver receiver(key);
// 	Transmitter transmitter(key);
// 	// string cipheredMsg = transmitter.cipher(msg);
// 	transmitter.cipher(msg);
// 	cout << "ciphered\t: " << msg << endl;
// 	cout << "crypto analysis" << endl;
// 	string interception = msg;
// 	cryptoAnalysis(interception);
// 	receiver.descipher(msg);
// 	cout << "desciphered\t: " << msg << endl;

// 	return 0;
// }
