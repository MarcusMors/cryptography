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

#define DEBUGGING 0
#ifdef DEBUGGING
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
	T auxA{t_integer};
	T auxB{t_mod_base};

	// non-recursive euclidian / doing euclidean division
	while (mod(t_integer, t_mod_base) != 0)
	{
		T temp = t_mod_base;
		t_mod_base = mod(t_integer, t_mod_base);
		t_integer = temp;
		cont++;
	}

	cont = cont + 2;
	T g[cont]{auxA, auxB};
	T y[cont];
	T u[cont]{1, 0};
	T v[cont]{0, 1};

	T i{1};
	while (true)
	{
		y[i + 1] = g[i - 1] / g[i];
		g[i + 1] = g[i - 1] - (y[i + 1] * g[i]);
		u[i + 1] = u[i - 1] - (y[i + 1] * u[i]);
		v[i + 1] = v[i - 1] - (y[i + 1] * v[i]);
		if (g[i + 1] == 0)
		{
			if (DEBUGGING)
			{
				std::cout << "mod(u[" << i << "]"
						  << "g[" << 1 << "]) : " << u[i] << '%' << g[1] << " : " << mod(u[i], g[1]) << std::endl;
			}
			return mod(u[i], g[1]);
		}
		i++;
	}
}

#endif // __INVERSE_H__
