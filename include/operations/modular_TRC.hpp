#ifndef __MODULAR_TRC_H__
#define __MODULAR_TRC_H__

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

#include "./module.hpp"
#include "./exponentiation.hpp"
#include "./inverse.hpp"

namespace operations
{
	template <typename T>
	T modular_TRC(T t_num, T t_d, T t_n, T t_p, T t_q);
} // namespace operations

template <typename T>
T operations::modular_TRC(T t_a, T t_e, T t_n, T t_p, T t_q)
{
	T a1, a2, d1, d2, P, P1, P2, q1, q2, D;
	// descompose
	d1 = mod(t_e, t_p - 1);
	d2 = mod(t_e, t_q - 1);
	a1 = exponentiation::modular(t_a, d1, t_p);
	a2 = exponentiation::modular(t_a, d2, t_q);

	// calculate P
	P = t_p * t_q;
	P1 = P / t_p;
	P2 = P / t_q;

	// q*P=1modp
	q1 = multiplicative_inverse(P1, t_p);
	q2 = multiplicative_inverse(P2, t_q);

	// D = a*P*q ..
	D = mod(mod(a1 * P1, P) * q1 + mod(a2 * P2, P) * q2, P);

	return D;
}

#endif // __MODULAR_TRC_H__
