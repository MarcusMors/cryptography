#ifndef __ENTITY_H_
#define __ENTITY_H_

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

namespace cryptography
{
	// class entity
	// {
	// private:
	// 	int m_key;
	// 	char *m_alphabet;
	// 	size_t m_alphabet_size;

	// public:
	// 	entity(int t_key, const char *t_alphabet, const size_t t_alphabet_size);
	// 	~entity();
	// };

	class entity
	{
	private:
		char *m_alphabet;
		size_t m_alphabet_size;

		// two positive primes integers
		NTL::ZZ p; // secret
		NTL::ZZ q; // secret

		// private key exponent that depends on n
		NTL::ZZ d; // secret

		// (n,d)
		NTL::ZZ m_private_key;
		// (n,e)
		NTL::ZZ m_public_key;

		// The size of an RSA key pair is commonly considered to be the length of the modulus n in bits (nlen).

		// entity data
		std::string m_full_name{};
		std::string m_email_address{};
		std::string m_description{};

		void set_alphabet(const char *t_alphabet, const size_t t_alphabet_size);
		void key_generation();
		void init();

	public:
		// The modulus n and the public key exponent e may be made known to anyone.
		// public key exponent
		// The exponent e shall be an odd, positive integer such that 2^16 < 𝑒 < 2^256
		NTL::ZZ e; // secret
		// n = pq
		NTL::ZZ n;

		// -------
		// For RSASSA-PSS, the length (in bytes) of the salt (sLen) shall satisfy 0 ≤ sLen ≤ hLen,
		// where hLen is the length of the hash function output block (in bytes).
		// -------

		// use of a modulus whose bit length is an even integer and greater than or equal to 2048 bits

		// compiled constructor
		entity(const char *t_alphabet, const size_t t_alphabet_size,
			   const std::string t_full_name = "", const std::string t_email_address = "",
			   const std::string description = "");

		// direct user input constructor
		entity(const char *t_alphabet, const size_t t_alphabet_size);

		~entity();

		void info();
	};

} // namespace cryptography

#endif // __ENTITY_H_

// plaintext
// ciphertext

// Decryption = The process of changing ciphertext into plaintext using a cryptographic algorithm and key
// Encryption The process of changing plaintext into ciphertext using a cryptographic algorithm and key.

// Entity : An individual (person), organization, device, or process; used interchangeably with “party.”

// Entropy : A  measure  of  the  disorder,  randomness,  or  variability  in  a  closed system; see SP 800 - 90B.

// Key agreement:
//  A  (pair-wise)  key-establishment  procedure  in  which  the  resultant
//  secret keying material is a function of information contributed by both
//  participants  so  that  neither  party  can  predetermine  the  value  of  the
//  secret keying material independently of the contributions of the other
//  party; contrast with key transport.
// Key-agreement primitive: A primitive algorithm used in a key-agreement scheme specified in SP 800-56A3 or SP 800-56B.

// Key derivation:
// 1.  A  process  by  which  one  or  more  keys  are  derived  from  a  shared
// secret and other information during a key-agreement transaction.
// 2. A process that derives new keying material from a key (i.e., a key-
// derivation key) that is currently available.

// Key-derivation key: A key used as an input to a key-derivation method to derive other keys;see SP 800-108.

// Key establishment: A procedure that results in secret keying material that is shared among different parties.
// Key expansion:
// The second step in the key-derivation procedure in which a key-
// derivation key is used to derive secret keying material having the
// desired length(s). The first step in the procedure is randomness
// extraction.

// Key extraction :See Randomness extraction.
// Key-generating module: A cryptographic module in which a given key is generated

// secret key:
// A cryptographic key used with an asymmetric-key (public-key)
// cryptographic  algorithm  that  is  not  made  public  and  is  uniquely
// associated with an entity that is authorized to use it. In an asymmetric-
// key  cryptosystem,  the  private  key  is  associated  with  a  public  key.
// Depending  on  the  algorithm  that  employs  the  private  key,  it  may  be

// used to:
// 1. Compute the corresponding public key;
// 2.  Compute  a  digital  signature  that  may  be  verified  using  the
// corresponding public key;
// 3. Decrypt data that was encrypted using the corresponding public
// key; or
// 4.  Compute  a  key-derivation  key,  which  may  then  be  used  as  an
// input to a key-derivation process.

// public key:
// A cryptographic key used with an asymmetric-key (public-key)
// cryptographic  algorithm  that  may  be  made  public  and  is  associated
// with a private key and an entity that is authorized to use that private
// key. Depending on the algorithm that employs the public key, it may

// be used to:
// 1. Verify  a  digital  signature  that  is  signed  by  the  corresponding

// private key;
// 2. Encrypt data that can be decrypted by the corresponding private
// key; or
// 3. Compute a piece of shared data (i.e., data that is known only by
// two or more specific entities).

// Random Bit Generator (RBG): A  device  or  algorithm  that  outputs  bits  that  are  computationally indistinguishable from bits that are independent and unbiased.

// Randomness extraction : The first step in the two-step key-derivation procedure during which a key-derivation key is produced. The second step in the procedure is key expansion

// Rekey:

// Salt: As used in this Recommendation, a byte string (which may be secret or non-secret) that is used as a MAC key

// acronyms:
// AES : Advanced Encryption Standard
// CMAC : Cipher-based MAC
// CTR : Counter mode for a block cipher algorithm
// DSA : Digital Signature Algorithm; see FIPS 18610
// ECDSA : Elliptic Curve Digital Signature Algorithm; see FIPS 186
// FIPS : Federal Information Processing Standard
// HMAC : Keyed-Hash Message Authentication Code; see FIPS 19811
// KDF : Key-Derivation Function
// KDM : Key-Deviation Method
// KMAC : KECCAK Message Authentication Code; see SP 800-18512
// MAC : Message Authentication Code
// NIST : National Institute of Standards and Technology
// RBG : Random Bit Generator
// RSA : Rivest-Shamir-Adleman
// SP : Special Publication

// || : Concatenation
// K  : The key to be determined
// kLen : The length of K in bits
// T(x, l) : Truncation of the bit string x to the leftmost l bits of x, where l ≤ the length of x in bits

// sources:
// - key generation https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-133r2.pdf
