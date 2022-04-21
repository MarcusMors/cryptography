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

// PUBLIC user made libs
#include "../../include/cryptography/rsa.hpp"
#include "../../include/operations/module.hpp"
#include "../../include/operations/exponentiation.hpp"
#include "../../include/operations/modular_TRC.hpp"
// user made libs
#include "../utils/find.hpp"
#include "../utils/cast.hpp"
// standard libraries
#include <string>

using namespace NTL;
using namespace utils;
using namespace std;
using namespace operations;

cryptography::RSA::RSA(int t_bits)
{
	m_bits = t_bits;
}

cryptography::RSA::RSA(ZZ t_e, ZZ t_n)
{
	m_e = t_e;
	m_n = t_n;
}

void cryptography::RSA::cipher(string t_plaintext)
{
	string t_cipherCode;
	string trans;
	string block;

	size_t message_size{t_plaintext.size()};
	auto n_size{ZZ_to_str(m_n).size()};
	auto extra{m_alphabet_size};
	auto MS_letter{ZZ_to_str(ZZ(extra - 1)).size()};

	string plus(to_string(extra));

	// TURN INTO DIGIT SEQUENCE

	for (size_t i = 0; i < message_size; i++)
	{
		int P = cstring_find(t_plaintext[i], m_alphabet, m_alphabet_size);
		int P_size = ZZ_to_str(ZZ(extra - 1)).size() - to_string(P).size();

		if (to_string(P).size() < MS_letter)
		{

			string zeros(P_size, '0');
			zeros += to_string(P);
			trans += zeros;
		}
		else
		{
			trans += to_string(P);
		}
	}

	while (mod(ZZ(trans.size()), ZZ(n_size - 1)) != 0 || mod(ZZ(trans.size()), ZZ(MS_letter)) != 0)
	{
		trans += plus;
	}

	// DIVIDE INTO BLOCKS

	ZZ C, num;

	for (int i = 0; i < trans.size(); i += n_size - 1)
	{

		num = conv<ZZ>(trans.substr(i, n_size - 1).c_str());

		C = exponentiation::modular(num, m_e, m_n);

		int C_size = n_size - ZZ_to_str(C).size();

		if (ZZ_to_str(C).size() < n_size)
		{

			string zeros(C_size, '0');
			zeros += ZZ_to_str(C);
			t_cipherCode += zeros;
		}
		else
		{
			t_cipherCode += ZZ_to_str(C);
		}
	}
	m_ciphered_letter = t_cipherCode;
}

void cryptography::RSA::decipher(string t_cipherCode)
{

	string t_plaintext, trans;

	auto message_size{t_plaintext.size()};
	auto n_size{ZZ_to_str(m_n).size()};
	auto extra{m_alphabet_size};
	auto MS_letter{ZZ_to_str(ZZ(extra - 1)).size()};

	// DIVIDE THE MESSAGE INTO N DIGITS

	ZZ C, num;

	for (size_t i = 0; i < t_cipherCode.size(); i += n_size)
	{

		num = conv<ZZ>(t_cipherCode.substr(i, n_size).c_str());

		C = operations::modular_TRC(num, m_d, m_n, m_p, m_q);

		int C_size = n_size - 1 - ZZ_to_str(C).size();

		if (ZZ_to_str(C).size() < n_size - 1)
		{

			string zeros(C_size, '0');
			zeros += ZZ_to_str(C);
			trans += zeros;
		}
		else
		{
			trans += ZZ_to_str(C);
		}
	}

	// REGROUP

	for (int i = 0; i < trans.size(); i += MS_letter)
	{

		num = conv<ZZ>(trans.substr(i, MS_letter).c_str());

		if (num < extra)
		{
			t_plaintext += m_alphabet[to_int(num)];
		}
	}
	m_message = t_plaintext;
}

void cryptography::RSA::info()
{
	std::cout << "\n___________________________________________\n";
	std::cout << "\n\tRSA - " << countBits(m_n);
	std::cout << "\np\t: " << m_p;
	std::cout << "\nq\t: " << m_q;
	std::cout << "\nn\t: " << m_n;
	std::cout << "\nphi\t: " << m_phi;
	std::cout << "\ne\t: " << m_e;
	std::cout << "\nd\t: " << m_d;
	std::cout << "\n___________________________________________\n";
}

// research :
// dillfie-hellman key exchange
