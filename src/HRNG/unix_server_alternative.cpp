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

// standard libraries
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

// user made PUBLIC libraries
#include <HRNG/unix_server_alternative.hpp>

// third party libraries

using namespace std;

unsigned int HRNG::random_unix_server_alt()
{
	unsigned int random_seed, random_seed_a{0}, random_seed_b, random_seed_c;

	ifstream file("/dev/urandom", std::ios::binary);

	if (file.is_open())
	{
		char *memblock;
		int size = sizeof(int);
		memblock = new char[size];
		file.read(memblock, size);
		file.close();

		random_seed_a = *reinterpret_cast<int *>(memblock);

		delete[] memblock;
	} // end if

	random_seed_b = time(NULL);

	srand((random_seed_b xor random_seed_a));

	random_seed_c = rand();

	random_seed = random_seed_a xor (random_seed_b xor random_seed_c);
	std::cout << "random_seed_a\t= " << random_seed_a << std::endl;
	std::cout << "random_seed_b\t= " << random_seed_b << std::endl;
	std::cout << "random_seed_c\t= " << random_seed_c << std::endl;
	std::cout << "random_seed\t= " << random_seed << std::endl;
	return random_seed;
} // end good_seed()

// https://stackoverflow.com/questions/2640717/c-generate-a-good-random-seed-for-psudo-random-number-generators
// ?????????
// then https://en.wikipedia.org/wiki/Mersenne_Twister
