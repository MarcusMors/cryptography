#ifndef __PRIMITIVE_ROOTS_H__
#define __PRIMITIVE_ROOTS_H__

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

#include <vector>
// user made libs
#include "./module.hpp"
#include "./gcd.hpp"
#include "./exponentiation.hpp"

namespace operations
{
	template <typename T>
	T smallest_primitive_root(T t_mod_base);

} // namespace operations

// template <typename T>
// void check_array(T *t_arr, auto t_arr_size, bool *t_check, T value)
// {
// 	for (auto i = 0; i < t_arr_size; i++)
// 	{
// 		if (value == t_arr[i])
// 		{
// 		}
// 	}
// }

// template <typename T>
// T operations::smallest_primitive_root(T t_mod_base)
// {
// 	// Checking the existence of primitive roots
// 	// 1.- get upper square root of t_mod_base
// 	// 1,2,4 p^k or 2p^k where p is a odd prime.

// 	T relative_primes[t_mod_base - 2];
// 	bool check[t_mod_base - 2];
// 	for (auto i = 2; i < t_mod_base; i++)
// 	{
// 		relative_primes[i - 1] = i;
// 		check[i - 1] = false;
// 	}

// 	for (auto i = 0; i < t_mod_base; i++)
// 	{
// 		// if (gcd::euclidean_iterative(i, t_mod_base) == 1)
// 		// {
// 		// }
// 		for (auto j = 1; j < i; j++)
// 		{
// 			T temp = exponentiation::binary(i, j, t_mod_base);
// 		}
// 	}
// }

template <typename T>
T operations::smallest_primitive_root(T t_mod_base)
{
	std::vector<T> factors;

	T phi = t_mod_base - 1;
	T n = phi;

	for (T i = 2; i * i <= n; ++i)
	{
		if (mod(n, i) == 0)
		{
			factors.push_back(i);
			while (mod(n, i) == 0)
			{
				n /= i;
			}
		}
	}

	if (n > 1)
	{
		factors.push_back(n);
	}

	for (T res = 2; res <= t_mod_base; ++res)
	{
		bool ok = true;

		for (T i = 0; i < factors.size() && ok; ++i)
		{
			ok &= operations::exponentiation::binary(res, (phi / factors[i]), t_mod_base) != 1;
		}
		if (ok)
		{
			return res;
		}
	}
	return -1;
}

#endif // __PRIMITIVE_ROOTS_H__
