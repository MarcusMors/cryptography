#ifndef __PRIME_GENERATOR_H__
#define __PRIME_GENERATOR_H__

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

#include <NTL/mat_ZZ.h>

namespace primes
{
	NTL::ZZ generator_p();
	NTL::ZZ generator_q();
	// https://en.wikipedia.org/wiki/Sieve_of_Atkin
	// https://sandbox.mc.edu/~bennet/cs220c/code/pgenintro.html
	// https://www.ijser.org/researchpaper/Prime-Number-Generation-Using-Genetic-Algorithm.pdf

	// https://www.geeksforgeeks.org/how-to-generate-large-prime-numbers-for-rsa-algorithm/
} // namespace primes

NTL::ZZ primes::generator_p()
{
	return conv<NTL::ZZ>{"11213828783257636674220619211377018571334306362767092051455961583173293684360516333034386990018305155441663873340171989914065928643044014241712713006842941"};
}

NTL::ZZ primes::generator_q() |
{
	return conv<NTL::ZZ>{"12960833193832585510080816961698826807968502933592875738476118603220479045243111181469588479528358901325659212957956874242395825819989046449424749694008263"};
}

#endif // __PRIME_GENERATOR_H__
