#ifndef __CAST_H__
#define __CAST_H__

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
#include <sstream>
// third party libraries
#include <NTL/mat_ZZ.h>

namespace utils
{
	template <typename T>
	std::string to_binary(T t_n);

	std::string ZZ_to_str(NTL::ZZ t_a);
	// std::string to_int(NTL::ZZ t_a);
	// template <typename T>
	// void C_str_to_base();

} // namespace utils

template <typename T>
std::string utils::to_binary(T t_n)
{
	std::string r;
	while (t_n != 0)
	{
		r += (t_n % 2 == 0 ? "0" : "1");
		t_n >>= 1;
		// t_n /= 2;
	}
	return r;
}

std::string utils::ZZ_to_str(NTL::ZZ t_a)
{
	std::stringstream temp;
	temp << t_a;
	return temp.str();
}

// template <typename T>
// void utils::C_str_to_base()
// {
// }

template <typename T>
int countBits(T t_n)
{
	unsigned int count = 0;
	while (t_n != 0)
	{
		count++;
		t_n >>= 1;
	}
	return count;
}

template <typename T>
bool check(T t_p, T t_q)
{
	return (binaryGCD(t_p, t_q) == 1) ? 1 : 0;
}

#endif // __CAST_H__
