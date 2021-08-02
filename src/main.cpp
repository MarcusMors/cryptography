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
#include "headers/GCD.hpp"
#include "headers/ProjectConfig.h"

using namespace std;

int main()
{
	int a = 24;
	int b = 11;
	cout << GCD::euclidean_recursive(a, b) << endl;
	cout << GCD::euclidean_iterative(a, b) << endl;
	return 0;
}
