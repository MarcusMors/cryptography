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

namespace operations
{
	namespace inverse
	{
		template <typename T>
		T euclid_extended(T t_a, T t_b);
	} // namespace inverse

} // namespace operations

template <typename T>
T operations::inverse::euclid_extended(T t_a, T t_b)
{
	// based in this explanation https://www.youtube.com/watch?v=D289EF58Yrw
	T cont = 0;
	T auxA = t_a, auxB = t_b;
	// non-recursive euclidian / doing euclidean division
	while (mod(t_a, t_b) != 0)
	{
		T temp = t_b;
		t_b = mod(t_a, t_b);
		t_a = temp;
		cont++;
	}
	cont = cont + 2;
	T g[cont] = {auxA, auxB};
	T y[cont];
	T u[cont] = {1, 0};
	T v[cont] = {0, 1};

	T i = 1;
	while (true)
	{
		y[i + 1] = g[i - 1] / g[i];
		g[i + 1] = g[i - 1] - (y[i + 1] * g[i]);
		u[i + 1] = u[i - 1] - (y[i + 1] * u[i]);
		v[i + 1] = v[i - 1] - (y[i + 1] * v[i]);
		if (g[i + 1] == 0)
			return mod(u[i], g[1]);
		i++;
	}
}

#endif // __INVERSE_H__
