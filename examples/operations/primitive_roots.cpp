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
#include <operations/primitive_roots.hpp>
#include <operations/gcd.hpp>

using namespace std;
using namespace operations;

template <typename T>
void display(T test_data[2])
{
	const T modular_base = test_data[0];
	const T expected_answer = test_data[1];
	cout << modular_base << " smallest primitive root is\t: " << smallest_primitive_root(modular_base) << " = " << expected_answer << '\n';
}

int main()
{
	long long integers__bases__answers[6][2] = {
		{5, 2},		 // 2,3
		{100049, 6}, // 6,7,12,14,15,19,23,24,28,31,35,38,39,46,47,48,51,56,60

	};

	cout << "EXAMPLES of finding the smallest primitive root:\n";
	for (auto i = 0; i < 2; i++)
	{
		display(integers__bases__answers[i]);
	}
	cout << endl;

	const long long modular_base = 100049;
	const long long g = smallest_primitive_root(modular_base);

	for (long long i = 2; i < modular_base; i++)
	{
		const auto x = operations::exponentiation::binary(g, i, modular_base);
		if (x == 2021)
		{
			std::cout << "x = " << i << '\n';
			break;
		}
	}

	cout << endl;
	cout << "PROCESS HAS ENDED" << endl;

	return 0;
}
