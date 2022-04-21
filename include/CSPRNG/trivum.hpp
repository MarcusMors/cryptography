#ifndef __TRIVUM_H__
#define __TRIVUM_H__

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

// Standard Libraries
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>

// PUBLIC User made libraries

// Third party libraries
#include <NTL/mat_ZZ.h>

namespace CSPRNG
{
	// pass statistical randomness tests
	// pass the next bit test (entropy test)

	// attacks:
	// DUHK attack
	// Japanese PURPLE cipher machine
	class Trivium
	{
	private:
		int m_s[288]{};
		int m_IV[80]{}, m_key[80]{};
		int m_t1{}, m_t2{}, m_t3{};
		NTL::ZZ m_base1;

		void generate_m_key_and_IV();

		void rotate();

		void init();

		void m_key_stream(int);

		int count_Bits(NTL::ZZ);

	public:
		Trivium();

		NTL::ZZ random_bits(int);

		NTL::ZZ random_range(NTL::ZZ, NTL::ZZ);
	};

	NTL::ZZ CSPRNG::random_prime(int bits);

	NTL::ZZ CSPRNG::random_number(NTL::ZZ init, NTL::ZZ end);

} // namespace CSPRNG

#endif // __TRIVUM_H__
