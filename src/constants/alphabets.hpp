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

namespace alphabet
{
	const char lower_case[]{"abcdefghijklmnopqrstuvwxyz "};
	const char upper_case[]{"ABCDEFGHIJKLMNOPQRSTUVWXYZ "};
	const char numeric[]{"0123456789 "};
	const char special_characters[]{"@$#&{}[]()<>~^_|+-*/%= "};
	const char punctuation_symbols[]{",.;:\"'?! "};
	const char all_case[]{"abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	const char numeric_lower_case[]{"0123456789abcdefghijklmnopqrstuvwxyz "};
	const char numeric_upper_case[]{"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ "};
	const char numeric_all_case[]{"0123456789abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	const char phonetic[]{"0123456789abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	const char alphanumeric[]{"0123456789abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ@$#&{}[]()<>~^_|+-*/%=,.;:\"'?!"};
}

#endif // __ALPHABETS_H__
