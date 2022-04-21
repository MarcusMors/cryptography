#ifndef __RSA_H__
#define __RSA_H__

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

// #include "./abstracts/key_generator.hpp"

// standard libraries
#include <string>
// third party libraries
#include "NTL/mat_ZZ.h"
// user made PUBLIC libraries

namespace cryptography
{
	typedef long long int llint;

	class RSA
	{
	private:
		NTL::ZZ m_d{};
		NTL::ZZ m_p{};
		NTL::ZZ m_q{};
		NTL::ZZ m_phi{};
		int m_bits{64};
		char *m_alphabet;
		size_t m_alphabet_size;

		void info(int);

	public:
		// 1 < e < phi(n)
		// coprime with n and phi(n)
		NTL::ZZ m_e{};
		NTL::ZZ m_n{};

		std::string m_ciphered_letter;
		std::string m_message;

		// char *m_message;
		// char *m_ciphered_letter;

		/**
		 * @brief Construct a new RSA object for the RECEIVER with N BITS
		 *
		 * @param t_bits
		 */
		RSA(int t_bits);

		/**
		 * @brief Construct a new RSA object for the SENDER
		 *
		 * @param t_e
		 * @param t_n
		 */
		RSA(NTL::ZZ t_e, NTL::ZZ t_n);

		/**
		 * @brief Construct a new RSA object for the RECEPTOR
		 *
		 * @param t_e
		 * @param t_d
		 * @param t_n
		 */
		RSA(NTL::ZZ t_e, NTL::ZZ t_d, NTL::ZZ t_n);

		~RSA();

		void cipher(std::string);
		void decipher(std::string);

		void show_ciphered();
		void show_deciphered();

		/**
		 * @brief Give information about the algorithm
		 *
		 */
		void info();
	};

} // namespace cryptography

#endif // __RSA_H__
