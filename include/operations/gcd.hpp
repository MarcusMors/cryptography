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

#endif // __GCD_H__
