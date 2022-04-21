#ifndef __CAESAR_H__
#define __CAESAR_H__

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

// namespace caesar
// {
// 	void cipher(char &msg, int iKey);
// 	void descipher(std::string &msg, int iKey);
// 	void cryptoAnalysis(std::string &msg);
// } // namespace caesar

#include <string_view>

class Caesar
{
private:
	std::string_view alphabet;

public:
	Caesar(const std::string_view &t_alphabet) : alphabet{t_alphabet} {}
	// char *cipher(const char *&t_msg);
	void cipher(std::string_view &t_msg, const int &t_key);
	// char *descipher(const char *&t_msg);
	void descipher(std::string_view &t_msg, const int &t_key);
	void crypto_analysis(char t_msg[]);
};

#endif // __CAESAR_H__
