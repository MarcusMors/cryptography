#ifndef __INVERSE_H__
#define __INVERSE_H__

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

#define DEBUGGING_TABLE 1
#ifdef DEBUGGING_TABLE
#include <iostream>
#endif

#include <stdexcept>
// user made libs
#include "./module.hpp"
#include "./gcd.hpp"

namespace operations
{
	namespace inverse
	{
		/**
		 * @brief returns the modular multiplicative inverse of a given integer in a given modular base
		 *
		 * @details The multiplicative inverse of a mod_base exists if and only if integer and mod_base are coprime gcd(integer, mod_base) = 1.
		 *
		 * @tparam T integer
		 * @param t_integer number which we will find its mod multiplicative inverse
		 * @param t_mod_base modular base
		 * @return T  t_integer^{-1} : modular multiplicative inverse of t_integer in t_mod_base
		 */
		template <typename T>
		T euclid_extended(T t_integer, T t_mod_base);
	} // namespace inverse

} // namespace operations

template <typename T>
T operations::inverse::euclid_extended(T t_integer, T t_mod_base)
{
	// coprime checking.
	if (gcd::euclidean_iterative(t_integer, t_mod_base) != 1)
	{
		throw std::invalid_argument("the integer and the modular base aren't coprime");
	}

	// based in this explanation https://www.youtube.com/watch?v=D289EF58Yrw
	T cont{0};
	T integer{t_integer};
	T mod_base{t_mod_base};

	// doing euclidean division to get the number of iterations, thus the array size.
	while (t_mod_base != 0)
	{
		T aux{t_mod_base};

		t_mod_base = mod(t_integer, t_mod_base);
		t_integer = aux;
		cont++;
	} // another solution is: cont = log2(t_integer);

	T quotients[cont];
	cont += 2;
	T remainders[cont]{integer, mod_base};
	T v[cont]{1, 0}; // (v[2], v[3]) always will be (1 , -quotients[3])

	/** i * quotients_i * remainders_i * v_i                   *
	 *  0 * -           * integer      * 0                     *
	 *  1 * -           * mod_base     * 1                     *
	 *  2 * int//base   * int%base     * v_0-(quotients_2*v_1) *
	 * ...* ...         * ...          * ...                   */

	if (DEBUGGING_TABLE)
	{
		std::cout << "\ni\tquotients_i\tremainders_i\tv_i\n";
	}

	T i{1};
	while (true)
	{
		const T next = i + 1;
		const T prev = i - 1;
		const T q_next = i - 1;

		if (DEBUGGING_TABLE)
		{
			T Q = quotients[i - 2];
			if ((prev == 0) || (prev == 1))
			{
				Q = 0;
			}

			std::cout << prev << '\t' << Q << "\t\t" << remainders[i] << "\t\t" << v[i] << std::endl;
		}

		quotients[q_next] = remainders[prev] / remainders[i];
		remainders[next] = remainders[prev] - (quotients[q_next] * remainders[i]);
		std::cout << "v[" << next << "] = " << v[prev] << " - (" << quotients[q_next] << " * " << v[i] << ")\n";
		v[next] = v[prev] - (quotients[q_next] * v[i]);

		if (remainders[next] == 0)
		{
			if (DEBUGGING_TABLE)
			{
				T Q = quotients[q_next];
				if ((i == 0) || (i == 1))
				{
					Q = 0;
				}

				std::cout << i << '\t' << Q << "\t\t" << remainders[next] << "\t\t" << v[next] << std::endl;
			}
			return mod(v[i], remainders[1]); // since mod(-v[i], k) = mod(v[i], k)
		}
		i++;
	}
}

#endif // __INVERSE_H__
