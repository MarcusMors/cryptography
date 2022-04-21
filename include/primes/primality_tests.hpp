#ifndef __PRIMALITY_TESTS_H__
#define __PRIMALITY_TESTS_H__

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

// PUBLIC user made libraries
#include "../operations/module.hpp"

namespace primes
{
	template <typename T>
	bool miller_rabin_test(T, T);

	template <typename T>
	bool isPrime(T number, T iter);
	// enhanced miller rabin Probabilistic Primality Test
	// (GENERAL) Lucas Probabilistic Primality Test
} // namespace primes

template <typename T>
bool MillerRabinTest(T t_d, T t_n)
{
	// get a rand number between the range [2...n-2]
	T a = RandomNumber(T(2), t_n - 2);

	// X =  a^d mod( t_n)
	T x = modPow(a, t_d, t_n);

	if (x == 1 || x == t_n - 1)
		return true;
	while (t_d != t_n - 1)
	{
		x = mod(x * x, t_n);

		// x= x*x % n;
		t_d *= 2;
		if (x == 1)
		{
			return false;
		}
		if (x == t_n - 1)
		{
			return true;
		}
	}
	return false;
}

template <typename T>
bool isPrime(T number, T iter)
{
	// Base cases
	if (mod(number, T(2)) == 0)
	{
		return false;
	}
	if (number <= 1 || number == 4)
	{
		return false;
	}
	if (number <= 3)
	{
		return true;
	}

	// number-1 = 2^d * r ; r >= 1
	T d = number - 1;

	// find the exponent of d
	while (mod(d, T(2)) == 0)
	{
		d /= 2;
	}

	// Iteration
	for (T i(0); i < iter; i++)
	{
		if (!MillerRabinTest(d, number))
		{
			return false;
		}
	}

	return true;
}
#endif // __PRIMALITY_TESTS_H__
