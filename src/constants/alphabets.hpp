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
	char lower_case[] = "abcdefghijklmnopqrstuvwxyz";
	char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char numeric[] = "0123456789";
	char special_characters[] = "@$#&{}[]()<>~^_|+-*/%=";
	char punctuation_symbols[] = ",.;:\"'?!";
	char all_case[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char numeric_lower_case[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char numeric_upper_case[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char numeric_all_case[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char phonetic[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char alphanumeric[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@$#&{}[]()<>~^_|+-*/%=,.;:\"'?!";
}

#endif // __ALPHABETS_H__
