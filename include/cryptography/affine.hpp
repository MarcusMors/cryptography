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

#include <string>
namespace affine
{
	class Affine
	{
	private:
		int Euclid_extended(int a, int b);

	public:
		std::string cipher(std::string t_msg, int t_key[2]);
		std::string descipher(std::string t_msg, int t_key[2]);
	};

	class Transmitter
	{
	private:
		int key[2]{0, 0};

	public:
		Transmitter(int t_key[2]);
		std::string cipher(std::string t_msg);
	};
	class Receiver
	{
	private:
		int key[2]{0, 0};

	public:
		Receiver(int t_key[2]);
		std::string descipher(std::string t_msg);
	};

}
