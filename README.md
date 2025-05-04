# Square Matrix (SquareMat)

An implementation of a square matrix class in C++ with complete operator overloading.

## Description

The `SquareMat` class provides a full implementation of a square matrix with a wide range of mathematical operations, including:
- Basic arithmetic operations (addition, subtraction, multiplication, division)
- Matrix multiplication
- Element-wise multiplication
- Matrix power
- Determinant calculation
- Transposition
- Comparison operators
- Increment and decrement operators

## Class Details

The `SquareMat` class is a comprehensive implementation of a square matrix in C++ with the following features:

### Characteristics
- Square matrix with equal number of rows and columns
- Uses dynamic memory allocation for matrix storage
- Stores values of type `double`

### Supported Operations
- **Basic Arithmetic Operations**: Addition (`+`), Subtraction (`-`), Multiplication (`*`), Division (`/`)
- **Matrix Multiplication**: Multiplication between two square matrices
- **Element-wise Multiplication**: Multiply corresponding elements between two matrices using the `%` operator
- **Power**: Raise a matrix to an integer power using the `^` operator
- **Determinant Calculation**: Using the `!` operator
- **Increment and Decrement**: `++` and `--` operators to modify all matrix elements
- **Element Access**: Using the `[][]` operator
- **Comparison**: `==`, `!=`, `<`, `>`, `<=`, `>=` operators for matrix comparison
- **I/O Operations**: `<<` and `>>` operators for reading and writing matrices

### Memory Management
- **Copy Constructor**: Creates a deep copy of a matrix
- **Assignment Operator**: Safe assignment with handling of self-assignment
- **Destructor**: Properly releases all allocated memory

### Exception Handling
- Validation of matrix size
- Compatibility checks between matrix sizes in operations
- Handling of division by zero and other invalid input cases

## Project Structure

- `squaremat.hpp` - Header file containing the class definition
- `squaremat.cpp` - Class implementation
- `main.cpp` - Usage examples
- `Test.cpp` - Comprehensive unit tests
- `makefile` - For project compilation
- `doctest.h` - Testing library

## Requirements

- C++ compiler supporting C++17 standard or newer
- Make (optional, for use with the makefile)

## Compilation and Execution

To build the program:
```
make 
```

To run the usage example:
```
make Main
```

To run the tests:
```
make test
./Test
```
To run the valgrind:
```
make valgrind
```

## Implemented Features

- Full operator overloading
- Friend functions
- Dynamic memory management
- Exception handling
- IO operator overloading

## Author

- Email: orel8155@gmail.com 