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
// PUBLIC User made libraries
#include "../../include/CSPRNG/trivum.hpp"
#include "../../include/HRNG/unix.hpp"
// Third party libraries

using namespace NTL;

CSPRNG::Trivium::Trivium()
{
	init();
}

void CSPRNG::Trivium::generate_m_key_and_IV()
{
	for (int i = 0; i < 80; i++)
	{
		const unsigned seed{HRNG::random_unix()};
		m_IV[i] = to_int(mod(seed, ZZ(2)));
		m_key[i] = to_int(mod(seed, ZZ(2)));
	}
}

void CSPRNG::Trivium::rotate()
{
	for (int j = 93; j >= 1; --j)
	{
		m_s[j] = m_s[j - 1];
	}
	for (int j = 177; j >= 94; --j)
	{
		m_s[j] = m_s[j - 1];
	}
	for (int j = 288; j >= 178; --j)
	{
		m_s[j] = m_s[j - 1];
	}

	m_s[0] = m_t3;
	m_s[93] = m_t1;
	m_s[177] = m_t2;
}

void CSPRNG::Trivium::init()
{
	generate_m_key_and_IV();

	for (int i = 0; i < 288; i++)
	{
		m_s[i] = 0;
	}

	for (int i = 0; i < 80; ++i)
	{
		m_s[i] = m_key[i];
		m_s[i + 93] = m_IV[i];
	}
	for (int i = 285; i < 288; ++i)
	{
		m_s[i] = 1;
	}

	// rotate
	for (int i = 1; i < 1152; i++)
	{
		m_t1 = ((m_s[65] ^ (m_s[90] & m_s[91])) ^ m_s[92]) ^ m_s[170];
		m_t2 = ((m_s[161] ^ (m_s[174] & m_s[175])) ^ m_s[176]) ^ m_s[263];
		m_t3 = ((m_s[242] ^ (m_s[285] & m_s[286])) ^ m_s[287]) ^ m_s[68];
		rotate();
	}
}

void CSPRNG::Trivium::m_key_stream(int N)
{
	ZZ z(0);
	m_base1 = 0;
	for (int i = 0; i < N; i++)
	{

		m_t1 = m_s[65] ^ m_s[92];
		m_t2 = m_s[161] ^ m_s[176];
		m_t3 = m_s[242] ^ m_s[287];

		z = m_t1 ^ m_t2 ^ m_t3;

		m_t1 ^= m_s[90] ^ m_s[91] & m_s[170];
		m_t2 ^= m_s[174] ^ m_s[175] & m_s[263];
		m_t3 ^= m_s[285] ^ m_s[286] & m_s[68];
		rotate();
		m_base1 += z << i;
	}
}

int CSPRNG::Trivium::count_bits(ZZ number)
{
	unsigned int count = 0;
	while (number != 0)
	{
		count++;
		number >>= 1;
	}
	return count;
}

ZZ CSPRNG::Trivium::random_bits(int bits)
{
	do
	{
		m_key_stream(bits);
	} while (count_Bits(m_base1) != bits);

	return m_base1;
}

ZZ CSPRNG::Trivium::random_range(ZZ init, ZZ end)
{
	int bits = count_Bits(end);
	do
	{
		m_key_stream(bits);
	} while (!(m_base1 >= init && m_base1 <= end));

	return m_base1;
}

ZZ CSPRNG::random_number(ZZ init, ZZ end)
{
	Trivium x;
	return x.random_range(init, end);
}

ZZ CSPRNG::random_prime(int bits)
{
	Trivium x;
	ZZ num;
	do
	{
		num = x.random_bits(bits);
	} while (!(isPrime(num, ZZ(5))));

	return num;
}
