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
#include <iostream>
// user made PUBLIC libraries
#include <HRNG/unix.hpp>

using namespace std;

int main()
{
	unsigned seed = HRNG::random_unix();
	std::cout << seed << std::endl;
	std::cout << HRNG::free_disk_space() << std::endl;
	return 0;
}
