<!--
 Copyright (C) 2021 José Enrique Vilca Campana

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU Affero General Public License as
 published by the Free Software Foundation, either version 3 of the
 License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Affero General Public License for more details.

 You should have received a copy of the GNU Affero General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
-->

# Abstract Algebra Math Library

## Algorithms

- cryptography ciphers
- operations (module, inverse, gcd, mcm)
- CSPRNG (chacha20, trivium)
- seed-generators

## How to compile it

at the root of the project.

```bash
cmake -B build
cd build
make
```

## Where are the examples?

every sub library has its own directory in `examples/`
you can try any of the binaries by executing:

```bash
./<sub_library>_examples_<algorithm>
```

where:
- `<sub_library>`: is any of the sub libraries in include.
- `<algorithm>`: is the algorithm or set of them you want to try.

like the following:

```bash
./"operations_examples_inverse"
```
