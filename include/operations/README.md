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



<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Operations](#operations)
	- [What are these?](#what-are-these)
		- [Primitive_roots](#primitive_roots)
		- [modular inverse](#modular-inverse)
			- [explanation with example:](#explanation-with-example)
		- [GCD (Greatest Common Divisor)](#gcd-greatest-common-divisor)
		- [MCM (Minimum Common Multiple)](#mcm-minimum-common-multiple)
		- [Module (remainder operation)](#module-remainder-operation)
		- [Exponentiation and Modular Exponentiation](#exponentiation-and-modular-exponentiation)
	- [sources](#sources)

<!-- /code_chunk_output -->
# Operations
## What are these?
these are common operations in cryptography, number theory, and, in general, abstract algebra.

### Primitive_roots

**Compile** the code using:
```bash
cmake -B build
cd build
make
```
now, you are at `build/` directory.
**run** the **example** doing:
```bash
cd examples/operations
./operations_examples_primitive_roots
```

### modular inverse

#### explanation with example:
inverse::euclid_extended(9,275)

| euclidean divisions    | same, but Remainder on the left | same, but quotient on the left | replacing the        |
| :--------------------- | ------------------------------- | ------------------------------ | -------------------- |
| $275 = 30 \cdot 9 + 5$ | $5 = 275 - (30 * 9)$            | $30 = (275 - 5) / 9$           | $30 = (275 - 5) / 9$ |
| $30 = 1 \cdot 5 + 4$   | $4 = 9 - (1 * 5)$               | $1 = (9 - 4) / 5$              | $1 = (9 - 4) / 5$    |
| $5 = 1 \cdot 4 + 1$    | $1 = 5 - (1 * 4)$               | $1 = (5 - 1) / 4$              | $1 = (5  - 1) / 4$   |
| $4 = 4 \cdot 1 + 0$    |                                 | $4 = (4 - 0) / 1$              | $4 = (4 - 0) / 1$    |

If we assign an order between remainders and quotients:
| euclidean divisions           | same, but Remainder on the left                 | same, but quotient on the left       | same, but quotient on the left       |
| :---------------------------- | ----------------------------------------------- | ------------------------------------ | ------------------------------------ |
| $R_0 = (Q_0 \cdot R_1) + R_2$ | $R_2 = R_0 - (Q_0 \cdot R_1)$                   | $Q_0 = (R_0 - R_2) / R_1$            | $R_1 = (R_0 - R_2) / Q_0$            |
| $R_1 = (Q_1 \cdot R_2) + R_3$ | $R_3 = R_1 - (Q_1 \cdot R_2)$                   | $Q_1 = (R_1 - R_3) / R_2$            | $R_2 = (R_1 - R_3) / Q_1$            |
| $R_2 = (Q_2 \cdot R_3) + R_4$ | $R_4 = R_2 - (Q_2 \cdot R_3)$                   | $Q_2 = (R_2 - R_4) / R_3$            | $R_3 = (R_2 - R_4) / Q_2$            |
| $R_3 = (Q_3 \cdot R_4) + R_5$ | **$R_{i+1} = R_{i-1} - (Q_{i-1} \cdot R_{i})$** | $Q_{i} = (R_{i} - R_{i+2})/ R_{i+1}$ | $Q_{i} = (R_{i} - R_{i+2})/ R_{i+1}$ |

| quotient on the left                 | quotient on the left, but replacing $R_{i}$ |
| ------------------------------------ | ------------------------------------------- |
| $Q_0 = (R_0 - R_2) / R_1$            | $Q_0 = (R_0 - R_2) / R_1$                   |
| $Q_1 = (R_1 - R_3) / R_2$            | $Q_1 = (R_1 - R_3) / R_2$                   |
| $Q_2 = (R_2 - R_4) / R_3$            | $Q_2 = (R_2 - R_4) / R_3$                   |
| $Q_{i} = (R_{i} - R_{i+2})/ R_{i+1}$ | $Q_{i} = (R_{i} - R_{i+2})/ R_{i+1}$        |

$R_{i+1} = R_{i-1} - (Q_{i+1} \cdot R_{i})$ is the following code line:
```c++
remainders[next] = remainders[prev] - (quotients[q_next] * remainders[i]);
```
and needs this to find the quotient:
```c++
> where remainder[0] = 275; // the modular base
> and remainder[1] = 9; // the integer
quotients[q_next] = remainders[prev] / remainders[i];
```

Definamos la secuencia $r_0 = a$, $r_1 = b$ y $i ← 2$.
encontremos cada $r$ por cada $i$ tal que $r_{i-2} = r_{i-1}q_{i} + r_{i}$.
También queremos a $r$ como una combinación lineal de $a$ y $b$, ejemplo: $r_i = s_{i}a + t_{i}b$

entonces:
$$r_i = s_{i_2}a + t_{i-2}b - (s_{i-1}a +t_{i-1}b)q_{i} = (s_{i-2} - s_{i-1}q_{i})a + (t_{i-2} - t_{i-1}q_{i})b$$

de aquí obtenemos $s_i = s_{i-2}- s_{i-1}q_{i}$ y $t_{i} = t_{i-2} - t_{i-1}q_{i}$.

Encontremos los valores iniciales de las secuencias ${s_i}$ y ${t_i​}$. por definición de $r_i$, tenemos:
- $$a=r_0=s_{0}a+t_{0}b  ⟹  s_{0}=1,t_{0}=0$$
- $$b=r_{1}=s_{1}a+t_{1}b  ⟹  s_1 = 0,t1=1$$

nos detenemos cuando el residuo sea 0, osea, $r_{i-1} = 0$



### GCD (Greatest Common Divisor)
### MCM (Minimum Common Multiple)
### Module (remainder operation)

### Exponentiation and Modular Exponentiation
## sources

- https://brilliant.org/wiki/extended-euclidean-algorithm/#extended-euclidean-algorithm
