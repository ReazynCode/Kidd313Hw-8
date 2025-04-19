# CMSC 313 – HW #8: Matrix Library in C and C++

## AUTHORING

- **Matt Nyandjo**
- UMBC – CMSC 313 (Computer Organization and Assembly Language Programming)
- Kid Kidd
- 2:30 Class

## PURPOSE OF SOFTWARE

This assignment implements a reusable matrix math library in both **C (C99)** and **C++ (C++17)**.  
The objective is to show how the same operations can be written in a procedural vs. object-oriented programming.

The program supports:
- Matrix Addition
- Scalar × Matrix Multiplication
- Matrix Transposition
- Matrix × Matrix Multiplication

## FILES

| File          | Description                                        |
|---------------|----------------------------------------------------|
| `Matrix.hpp`  | C++ header declaring the Matrix class              |
| `Matrix.cpp`  | C++ implementation of matrix functions             |
| `main.cpp`    | C++ test driver showing assignment & extra tests   |
| `matrix.h`    | C header declaring matrix struct and function APIs |
| `matrix.c`    | C implementation of matrix functions               |
| `main.c`      | C test driver showing assignment & extra tests     |
| `makefile`    | Builds both `test_cpp` and `test_c` executables    |
| `README.md`   | Project documentation and assignment compliance    |

## BUILD INSTRUCTIONS

To build the C and C++ versions using the provided `makefile`, run:

## BUILD INSTRUCTIONS

To compile using the Makefile:

```bash
# Compile both versions:
make

# Run the C++ version:
./test_cpp

# Run the C version:
./test_c
```
## TESTING METHODOLOGY

Both the C and C++ drivers go beyond the base assignment by running a full suite of tests to validate all functionality.

### The following test cases are included:

- **Assignment Equation:**  
  `D = A + (3 × B) × Cᵀ`

- **Matrix × Matrix Multiplication:**  
  `E = A × B`

- **Transpose + Matrix Multiplication:**  
  `F = C × Bᵀ`

- **Matrix Addition:**  
  `G = B + C`

- **Output Display:**  
  Matrices are printed in clean, readable form using:
  - A custom `print_matrix()` function in `main.c`
  - Overloaded `<<` operator in C++ via `Matrix.cpp`


# ADDITIONAL INFORMATION

- Tested in:
- **WSL2 (Ubuntu 22.04)** using `gcc 13.2`, `g++ 13.2`
- Compatible with Linux, macOS, and Windows (via Git Bash or WSL)
- Works with any x86 architecture as required by the assignment

- Code adheres strictly to:
- **C99 standard** (no GNU extensions)
- **C++17** (using initializer lists, overloading, etc.)

- No external libraries used (only `<vector>`, `<iostream>`, `<stddef.h>`, etc.)

