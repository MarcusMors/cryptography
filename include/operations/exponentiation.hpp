#ifndef __EXPONENTIATION_H__
#define __EXPONENTIATION_H__

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
#include <string>
#include <iostream>

// PUBLIC user made libraries
#include "./module.hpp"

namespace operations
{
	namespace exponentiation
	{
		using operations::mod;

		template <typename T>
		T fast(T base, T t_exponent, T t_mod_base);

		template <typename T>
		T binary(T t_base, T t_exponent, T t_mod_base);

		// template <typename T>
		// void right_to_left_binary(T g, T e, T m);

		// template <typename T>
		// void left_to_right_binary(T b, T e, T mod);

		template <typename T>
		T naive(T g, T e, T m);

		template <typename T>
		T modular(T a, T e, T n);
	} // namespace exponentiation

} // namespace operations

template <typename T>
T operations::exponentiation::fast(T base, T t_exponent, T t_mod_base)
{
	T temp;
	if (t_exponent == 0)
	{
		return 1;
	}
	if ((t_exponent & 1) == 0)
	{
		temp = fast(base, t_exponent >> 1, t_mod_base);
		return mod(temp * temp, t_mod_base);
	}
	temp = fast(base, (t_exponent - 1) >> 1, t_mod_base);
	return mod(base * mod(temp * temp, t_mod_base), t_mod_base);
}

template <typename T>
T operations::exponentiation::binary(T t_base, T t_exponent, T t_mod_base)
{
	// T result = (t_exponent & 1) ? t_base : 1;
	T result = 1;

	while (t_exponent > 0)
	{
		if (t_exponent & 1)
		{
			result = mod((result * t_base), t_mod_base);
		}

		t_base = mod((t_base * t_base), t_mod_base);
		t_exponent >>= 1;
	}

	return result;
}

template <typename T>
T modular(T a, T e, T n)
{
	T A(1);
	std::string bin = to_binary(e);
	for (int i = bin.size(); i != -1; i--)
	{
		A = mod(A * A, n);
		if (bin[i] == '1')
		{
			A = mod(A * a, n);
		}
	}
	return A;
}

// template <typename T>
// void operations::exponentiation::right_to_left_binary(T g, T e, T m)
// {
// 	T A{1};
// 	while (e != 0)
// 	{
// 		if ((e & 1) == 1)
// 		{
// 			A = mod(A * g, m);
// 		}
// 		e >>= 1;
// 		g = mod(g * g, m);
// 	}
// 	std::cout << A;
// }

// template <typename T>
// void operations::exponentiation::left_to_right_binary(T b, T e, T mod)
// {
// 	T A(1);
// 	std::string bin = toBinary(e);
// 	for (int i = bin.size(); i != -1; i--)
// 	{
// 		A = mod(A * A, mod);
// 		if (bin[i] == '1')
// 		{
// 			A = mod(A * b, mod);
// 		}
// 	}
// 	std::cout << A;
// }

template <typename T>
T operations::exponentiation::naive(T g, T e, T m)
{
	T A{1};
	for (int i = 0; i < e; i++)
	{
		A = mod(A * g, m);
	}
	return A;
}

#endif // __EXPONENTIATION_H__
