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

template <typename T>
void display(T test_data[3])
{
	const T integer = test_data[0];
	const T mod_base = test_data[1];
	const T expected_answer = test_data[2];
	cout << integer << " in base " << mod_base << " is\t: " << euclid_extended(integer, mod_base) << " = " << expected_answer << '\n';
}

int main()
{
	long long integers__bases__answers[6][3] = {
		{3, 26, 9},
		{29, 101, 7},
		{13, 14, 13},
		{31, 66, 49},
		{66, 31, 8},
		{9, 275, 214}

	};

	cout << "EXAMPLES Modular multiplicative inverse of:\n";
	for (auto i = 0; i < 6; i++)
	{
		display(integers__bases__answers[i]);
	}
	cout << endl;

	cout << "Try yourself! input 2 numbers, please.\n";
	int integer{0}, mod_base{0};
	cout << "integer\t: ";
	cin >> integer;
	cout << "modular base\t: ";
	cin >> mod_base;
	cout << integer << " in base " << mod_base << " is : " << euclid_extended(integer, mod_base) << '\n';
	cout << '\n';

	cout << "Here is an invalid argument exception example:\n";
	cout << "7 in base 14 is\t: " << std::flush << euclid_extended(7, 14) << endl;

	return 0;
}
