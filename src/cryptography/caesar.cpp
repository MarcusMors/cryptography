/**
 * @file caesar.cpp
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
#include <vector>
//user made public libs
#include <cryptography/caesar.hpp>
#include <operations/module.hpp>
//user made libs
#include "../constants/alphabets.hpp"
#include "../constants/letter_frequency.hpp"

using namespace std;
using namespace operations;

Caesar::Caesar(const char t_alphabet[], const unsigned t_alphabet_size)
{
	m_alphabet_size = t_alphabet_size - 1;
	m_alphabet = new char[m_alphabet_size];
	for (int i = 0; i < m_alphabet_size; i++)
	{
		m_alphabet[i] = t_alphabet[i];
	}
	cout << m_alphabet << endl;
}
void Caesar::cipher(char t_msg[], int t_key)
{
	const int msg_size = sizeof(t_msg) - 1;
	const int key = mod(t_key, m_alphabet_size);

	char ciphered[msg_size];

	for (int i = 0; i < msg_size; i++)
	{
		for (int j = 0; j < m_alphabet_size; j++)
		{
			if (t_msg[i] == m_alphabet[j])
			{
				ciphered[i] = m_alphabet[mod((j + key), m_alphabet_size)];
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

void Caesar::descipher(char t_msg[], int t_key)
{
	const int msg_size = sizeof(t_msg) - 1;
	const int key = mod(t_key, m_alphabet_size);

	char ciphered[msg_size];
	for (int i = 0; i < msg_size; i++)
	{
		for (int j = 0; j < m_alphabet_size; j++)
		{
			if (t_msg[i] == m_alphabet[j])
			{
				ciphered[i] = m_alphabet[mod((j + m_alphabet_size - key), m_alphabet_size)];
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

		for (int j = 0; j < m_alphabet_size; j++)
		{
			if (char(frequency[1][index]) == m_alphabet[j])
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
