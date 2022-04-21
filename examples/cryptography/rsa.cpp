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

// third party libraries
// standard libraries
#include <iostream>
// #include <fstream>
// #include <string>
// #include <string.h>
// #include <stdio.h>

// user made PUBLIC libraries
#include <cryptography/rsa.hpp>
#include <cryptography/entity.hpp>

// user made libraries
#include "../../src/constants/alphabets.hpp"

// configuration files
// #include "./ProjectConfig.h"

int main()
{
	const size_t common_alphabet_size = alphabet::alphanumeric_size;
	const char common_alphabet[common_alphabet_size] = alphabet::alphanum;
	// alphabet, alphabet_size
	Entity receiver(data, common_alphabet, common_alphabet_size);
	Entity sender(receiver.m_e, common_alphabet, common_alphabet_size);

	sender.m_message();

	receptor.decipher(cipher);
	receptor.show_deciphered();

	return 0;
}
