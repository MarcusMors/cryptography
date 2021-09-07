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
//user made public libs
#include <cryptography/caesar.hpp>
#include <operations/module.hpp>
//user made libs
#include "../constants/alphabets.hpp"

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
void Caesar::crypto_analysis(char t_msg[]) // desciph a message
{
	int msg_size = sizeof(t_msg) - 1;

	for (int key = 0; key < m_alphabet_size; key++)
	{
		char ciphered[msg_size];
		for (int i = 0; i < msg_size; i++)
		{
			for (int j = 0; j < m_alphabet_size; j++)
			{
				if (t_msg[i] == m_alphabet[j])
				{
					ciphered[i] = m_alphabet[(m_alphabet_size + j - key) % m_alphabet_size];
					break;
				}
			}
		}
		cout << "key : " << key << endl;
		for (int i = 0; i < msg_size; i++)
		{
			cout << ciphered[i];
		}
		cout << endl;
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
