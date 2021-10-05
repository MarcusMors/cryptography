/**
 * @file caesar.cpp
 * @author Jose Vilca Campana <@marcusmors> (alivezeh@gmail.com)
 * @brief caesar binary
 * @version 0.1
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */

// Copyright (C) 2021 José Enrique Vilca Campana
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

//third party dependencies
//standar libraries
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
//public libraries
#include <cryptography/caesar.hpp>
//configuration file
#include "./ProjectConfig.h"
#include "../src/constants/alphabets.hpp"
//user made libs

using namespace std;

void wizard(char &option);
enum choices : char
{
	c_1 = '0',
	c_2 = '1',
	c_3 = '2',
	c_4 = '3',
	c_5 = '4',
	c_6 = '5',
	c_7 = '6',
	c_8 = '7',
	c_9 = '8',
	c_10 = '9',
	c_11 = 'A',
};
void print_char_arr(const char t_array[], const int t_size);

/**
 * @brief cipher the content of a file, else receives a message to cipher by caesar
 *
 * @param argc number of files
 * @param argv file names
 * @return 0 if no errors, else 1.
 */
int main(int argc = 0, char *argv[] = nullptr)
{
	if (argc < 2)
	{
		/*
		const char *chosen_alphabet;
		char option;
		wizard(option);
		switch (option)
		{
		case choices::c_1:
			chosen_alphabet = alphabet::lower_case;
			break;
		case choices::c_2:
			chosen_alphabet = alphabet::upper_case;
			break;
		case choices::c_3:
			chosen_alphabet = alphabet::numeric;
			break;
		case choices::c_4:
			chosen_alphabet = alphabet::special_characters;
			break;
		case choices::c_5:
			chosen_alphabet = alphabet::punctuation_symbols;
			break;
		case choices::c_6:
			chosen_alphabet = alphabet::all_case;
			break;
		case choices::c_7:
			chosen_alphabet = alphabet::numeric_lower_case;
			break;
		case choices::c_8:
			chosen_alphabet = alphabet::numeric_upper_case;
			break;
		case choices::c_9:
			chosen_alphabet = alphabet::numeric_all_case;
			break;
		case choices::c_10:
			chosen_alphabet = alphabet::phonetic;
			break;
		case choices::c_11:
			chosen_alphabet = alphabet::alphanumeric;
			break;

		default:
			chosen_alphabet = alphabet::alphanumeric;
			break;
		}

		cout << "chosen_alphabet:\t" << chosen_alphabet << endl;
		cout << "size:\t" << sizeof(chosen_alphabet) / sizeof(char) << endl;
		Caesar caesar(chosen_alphabet, sizeof(chosen_alphabet));
		*/
		Caesar caesar(alphabet::lower_case, sizeof(alphabet::lower_case));

		string str;
		cout << "message:\t";
		getline(cin, str);
		int key;
		cout << "key:\t";
		cin >> key;

		char msg[str.size() + 1];
		cout << "str.size() : " << str.size() << endl;
		for (auto i = 0; i < str.size(); i++)
		{
			msg[i] = str[i];
		}

		cout << "Before encrypting:\t";
		print_char_arr(msg, str.size());
		caesar.cipher(msg, key);
		cout << "After encrypting:\t";
		print_char_arr(msg, str.size());

		cout << "Before desencrypting:\t";
		print_char_arr(msg, str.size());
		caesar.descipher(msg, key);
		cout << "After desencrypting:\t";
		print_char_arr(msg, str.size());

		cout << "crypto analysis..." << endl;
		caesar.crypto_analysis(msg);

		return 0;
	}
	if (argc < 2)
	{
		cout << argv[0] << " Version " << VERSION_MAJOR << "." << VERSION_MINOR << "\n";
		cout << "Usage:\t<number> <file_names>\n";
		cout << "\t<number>\t: the number of files to be ciphered\n";
		cout << "\t<file_names>\t: the name of the files\n"
			 << endl;

		cout << "you are seeing this because you have input the number only" << endl;
		return 0;
	}

	return 0;
}

void wizard(char &t_option)
{
	cout << "Choose an alphabet:\n";
	cout << "[" << char(choices::c_1) << "] -- " << alphabet::lower_case << "\t-- lower case\n";
	cout << "[" << char(choices::c_2) << "] -- " << alphabet::upper_case << "\t-- upper case\n";
	cout << "[" << char(choices::c_3) << "] -- " << alphabet::numeric << "\t-- numeric\n";
	cout << "[" << char(choices::c_4) << "] -- " << alphabet::special_characters << "\t-- special characters\n";
	cout << "[" << char(choices::c_4) << "] -- " << alphabet::punctuation_symbols << "\t-- punctuation symbols\n";
	cout << "[" << char(choices::c_5) << "] -- " << alphabet::all_case << "\t-- all case --\n";
	cout << "[" << char(choices::c_6) << "] -- " << alphabet::numeric_lower_case << "\t-- numeric lower case --\n";
	cout << "[" << char(choices::c_7) << "] -- " << alphabet::numeric_upper_case << "\t-- numeric upper case --\n";
	cout << "[" << char(choices::c_8) << "] -- " << alphabet::numeric_all_case << "\t-- numeric all case --\n";
	cout << "[" << char(choices::c_9) << "] -- " << alphabet::phonetic << "\t-- numeric all case --\n";
	cout << "[" << char(choices::c_10) << "] -- " << alphabet::alphanumeric << "\t-- numeric all case --\n";

	cout << "\nelection\t: \n";

	cin >> t_option;
	cout << endl;
}
void print_char_arr(const char t_array[], const int t_size)
{
	cout << "\"";
	for (int i = 0; i < t_size; i++)
	{
		cout << t_array[i];
	}
	cout << "\"" << endl;
}
