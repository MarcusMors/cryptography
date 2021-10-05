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

namespace operations
{
	/**
	 * @brief module operations
	 *
	 * @tparam T integer
	 * @param t_dividend number
	 * @param t_divisor modular base
	 * @return T module, t_dividend % t_divisor
	 */
	template <typename T>
	T mod(const T t_dividend, const T t_divisor);
} // namespace operations

template <typename T>
T operations::mod(const T t_dividend, const T t_divisor)
{
	const T quotient = t_dividend / t_divisor;
	const T remainder = t_dividend - (quotient * t_divisor);
	return remainder >= 0 ? remainder : remainder - t_divisor;
}

#endif // __MODULE_H__
