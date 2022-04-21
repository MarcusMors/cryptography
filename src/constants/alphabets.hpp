#ifndef __ALPHABETS_H__
#define __ALPHABETS_H__

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

#include <cstring> // this also includes size_t
#include <string>  // this includes basic_string<C>

namespace alphabet
{
	typedef std::basic_string<char> b_str;

	const b_str lower_case{"abcdefghijklmnopqrstuvwxyz"};
	const b_str upper_case{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	const b_str all_case{lower_case + upper_case};
	const b_str &alphabetic = all_case;

	const b_str numeric{"0123456789"};
	const b_str &digit = numeric;
	const b_str &d = numeric;

	const b_str special{"@$#&{}[]()<>~^_|+-*/%="};
	const b_str punctuation{",.;:\"'?!"};

	const b_str blank{" "}; // Any whitespace character except line separators
	const b_str &b = blank;

	const b_str space{" \n"}; // Any whitespace character
	const b_str &s = space;

	const b_str numeric_lower_case{d + lower_case};
	const b_str numeric_upper_case{d + upper_case};

	const b_str alphanum{d + alphabetic};
	const b_str &phonetic = alphanum;
	const b_str &numeric_all_case = alphanum;
	const b_str w{alphanum + '_'};
	const b_str everything{alphanum + punctuation + special + b};

} // namespace alphabet

#undef LOWER_CASE
#undef UPPER_CASE
#undef NUMERIC
#undef SPECIAL
#undef PUNCTUATION

#endif // __ALPHABETS_H__

// https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-repository-from-a-template
// https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-template-repository
