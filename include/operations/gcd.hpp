#ifndef __GCD_H__
#define __GCD_H__

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

namespace operations
{
	namespace gcd
	{
		/**
		 * @brief Euclidean gcd recursive algorithm
		 *
		 * @deprecated replace by{@euclidean_recursive} because recursion cost
		 * @tparam T any integer, non floating-point type.
		 * @param t_a
		 * @param t_b
		 * @return T integer, the greatest common divisor.
		 */
		template <typename T>
		T euclidean_recursive(T t_a, T t_b);

		/**
		 * @brief Euclidean gcd iterative algorithm
		 *
		 * @tparam T integer, non floating-point type.
		 * @param t_a
		 * @param t_b
		 * @return T integer, the greatest common divisor.
		 */
		template <typename T>
		T euclidean_iterative(T t_a, T t_b);

		template <typename T>
		T binary(T t_a, T t_b);

		template <typename T>
		void euclidean_extended(T a, T b, T &x, T &y);

	} // namespace gcd
} // namespace operations

template <typename T>
T operations::gcd::euclidean_recursive(T t_a, T t_b)
{
	if (t_b == 0)
		return t_a;
	return euclidean_recursive(t_b, mod(t_a, t_b));
}

template <typename T>
T operations::gcd::euclidean_iterative(T t_a, T t_b)
{
	while (t_b != 0)
	{
		T aux = t_b;

		t_b = mod(t_a, t_b);
		t_a = aux;
	}
	return t_a;
}

template <typename T>
T operations::gcd::binary(T &u, T &v)
{
	T t, g, a, b;
	g = 1;
	a = abs(u);
	b = abs(v);
	while (a % 2 == 0 && b % 2 == 0)
	{
		a = a / 2;
		b = b / 2;
		g = 2 * g;
	}
	while (a != 0)
	{
		if (a % 2 == 0)
		{
			a = a / 2;
		}
		else if (b % 2 == 0)
		{
			b = b / 2;
		}
		else
		{
			t = abs(a - b) / 2;
			if (a >= b)
			{
				a = t;
			}
			else
			{
				b = t;
			}
		}
	}
	return g * b;
}

template <typename T>
void euclidean_extended(T a, T b, T &x, T &y)
{
	x = T(1), y = T(0);

	T x1(0), y1(1), a1(a), b1(b);
	while (b1 != 0)
	{
		T q = a1 / b1;
		tie(x, x1) = make_tuple(x1, x - q * x1);
		tie(y, y1) = make_tuple(y1, y - q * y1);
		tie(a1, b1) = make_tuple(b1, a1 - q * b1);
	}
}

#endif // __GCD_H__
