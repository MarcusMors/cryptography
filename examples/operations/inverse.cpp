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

#include <iostream>
// user made libs
#include <operations/inverse.hpp>

using namespace std;
using namespace operations::inverse;

int main()
{
	cout << "Modular multiplicative inverse of:\n";
	cout << "3 in base 26 is\t: " << euclid_extended(3, 26) << " = 9\n";
	cout << "29 in base 101 is\t: " << euclid_extended(29, 101) << " = 7\n";
	cout << "13 in base 14 is\t: " << euclid_extended(13, 14) << " = 13\n";
	cout << '\n';
	cout << "Here is an invalid argument exception example:\n";
	cout << "7 in base 14 is\t: " << std::flush << euclid_extended(7, 14) << endl;

	return 0;
}
