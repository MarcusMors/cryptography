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

// user made PUBLIC libs
#include "../../include/cryptography/entity.hpp"
#include "../../include/CSPRNG/trivum.hpp"
#include "../../include/operations/inverse.hpp"

// standard libraries
#include <iostream>

using namespace std;
using namespace CSPRNG;

/******************************************************************************
 * PRIVATE
 *****************************************************************************/

void cryptography::entity::set_alphabet(
	const char *t_alphabet, const size_t t_alphabet_size)
{
	m_alphabet_size = t_alphabet_size;
	m_alphabet = new char[t_alphabet_size];

	for (size_t i = 0; i < t_alphabet_size; i++)
	{
		m_alphabet[i] = t_alphabet[i];
	}
}

void cryptography::entity::init()
{
	key_generation();
	Trivium();
}

void cryptography::entity::info()
{
	std::cout << "\n___________________________________________\n";
	std::cout << "\n\tentity - " << countBits(m_n);
	std::cout << "\n";
	std::cout << "\nfull name\t: " << m_full_name;
	std::cout << "\nemail address\t: " << m_email_address;
	std::cout << "\ndescription\t: " << m_description;
	std::cout << "\n";
	std::cout << "\npublic key\t: " << m_public_key;
	std::cout << "\n___________________________________________\n";
}
// ----------------------------------------------------------------------------
/**
 * @brief get a random number.
 *
 * @param t_bit_length The intended bit length of the modulus n.
 * @return unsigned status. The status to be returned, where status is either SUCCESS or FAILURE.
 * @return unsigned seed. The seed. If status = FAILURE, a value of zero is returned as the seed
 * @subsection process Process:
 * 1. If nlen is not valid (see Section 5.1), then Return (FAILURE, 0).
 * 2. Let security_strength be the security strength associated with nlen as specified in SP 800-57, Part 1.
 * 3. Obtain a string seed of (2 * security_strength) bits from an RBG that supports the security_strength.
 * 4. Return (SUCCESS, seed).
 *
 */
unsigned seed_generator(unsigned t_bit_length)
{
	bool status = true;
	const unsigned minimum_bit_length{1024};
	if (status == false) // FAILURE
	{
		return 0;
	}
	// A CA should use a modulus whose length nlen is equal to or greater than the bit-length of every modulus used by its subscribers. For example, if the subscribers are using nlen = 2048, then the CA should use nlen ≥ 2048.
}

ZZ random_prime_generator()
{
}

// ----------------------------------------------------------------------------

void cryptography::entity::generate_key(int t_bits)
{
	// find p and q

	// Find n
	do
	{
		m_p = RandomPrime(bits / 2);
		m_q = RandomPrime(bits / 2);
		m_n = m_p * m_q;
	} while (countBits(n) != bits);

	// find phi
	m_phi = (m_p - 1) * (m_q - 1);

	// 1 < e < phi
	do
	{
		m_e = RandomNumber(T(2), m_phi - 1);
	} while (binaryGCD(m_e, m_phi) != 1);

	// find d
	//  1 < d < phi -> inverse gcd(e,phi)
	m_d = multiplicative_inverse(m_e, m_phi);

	info();
}

/******************************************************************************
 * PUBLIC
 *****************************************************************************/

cryptography::entity::entity(
	const char *t_alphabet, const size_t t_alphabet_size, const int t_key_bit,
	const string t_full_name = "",
	const string t_email_address = "",
	const string description = "")
{
	set_alphabet(t_alphabet, t_alphabet_size);

	m_full_name = t_full_name;
	m_email_address = t_email_address;
	m_description = t_description;
	init();
}
cryptography::entity::entity(const char *t_alphabet, const size_t t_alphabet_size,
							 const int t_key_bits = 1024)
{
	set_alphabet(t_alphabet, t_alphabet_size);

	cout << "full name\t:\n";
	cin >> m_full_name;
	cout << "email address\t:\n";
	cin >> m_email_address;
	cout << "key description\t:\n";
	cin >> m_description;

	m_key_bits = t_key_bits;
	while (m_key_bits < 64)
	{
		cout << "too few bits, it is insecure, the minimum is 64 bits\n";
		cout << "key bits\t:\n";
		cin >> m_key_bits;
	}

	cin >> m_description;

	init();
}
