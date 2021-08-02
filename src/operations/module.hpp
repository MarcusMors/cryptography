#ifndef __MODULE_H__
#define __MODULE_H__

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

template <typename T>
T operator%(T lhs_dividend, T const rhs_divisor)
{
	constexpr T quotient = lhs_dividend / rhs_divisor;
	constexpr T remainder = lhs_dividend - (quotient * rhs_divisor);
	return remainder > -1 ? remainder : remainder - rhs_divisor;
}

template <typename T>
T operator%=(T &lhs_dividend, T const rhs_divisor)
{
	constexpr T quotient = lhs_dividend / rhs_divisor;
	constexpr T remainder = lhs_dividend - (quotient * rhs_divisor);
	lhs_dividend = remainder > -1 ? remainder : remainder - rhs_divisor;
	return *lhs_dividend;
}

#endif // __MODULE_H__
