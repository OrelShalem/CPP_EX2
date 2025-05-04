// orel8155@gmail.com
#pragma once         // Ensures the header file is included only once
#include <iostream>  // Include for input/output operations
#include <stdexcept> // Include for standard exceptions
#include <cmath>     // Include for mathematical functions

/**
 * @namespace squaremat
 * @brief Namespace containing the SquareMat class for square matrix operations
 */
namespace squaremat // Start of namespace definition
{
    /**
     * @class SquareMat
     * @brief A class representing a square matrix with various mathematical operations
     *
     * This class provides functionality for square matrices including basic arithmetic
     * operations, matrix multiplication, determinant calculation, and more.
     */
    class SquareMat // Class definition for square matrix
    {
    private:
        size_t size;     ///< Size of the square matrix (number of rows/columns) - Unsigned integer
        double **matrix; ///< 2D array to store matrix elements - Pointer to array of pointers

    public:
        /**
         * @brief Constructor that creates a square matrix of specified size
         * @param size The size of the square matrix (number of rows/columns)
         * @throws std::invalid_argument if size is not positive
         */
        SquareMat(size_t size) : size(size), matrix(new double *[size]) // Constructor with initialization list
        {
            if (size <= 0) // Check if size is valid
            {
                throw std::invalid_argument("Size must be positive"); // Throw exception for invalid size
            }
            for (size_t i = 0; i < size; i++) // Loop through each row
            {
                matrix[i] = new double[size](); // Allocate memory for each row and initialize to 0
            }
        }

        /**
         * @brief Copy constructor
         * @param other The matrix to copy
         */
        SquareMat(const SquareMat &other) : size(other.size), matrix(new double *[other.size]) // Copy constructor with initialization list
        {
            for (size_t i = 0; i < size; i++) // Loop through each row
            {
                matrix[i] = new double[size];     // Allocate memory for each row
                for (size_t j = 0; j < size; j++) // Loop through each column
                {
                    matrix[i][j] = other.matrix[i][j]; // Copy values from other matrix
                }
            }
        }

        /**
         * @brief Destructor to free allocated memory
         */
        ~SquareMat() // Destructor definition
        {
            if (matrix != nullptr) // Check if matrix is not null
            {
                for (size_t i = 0; i < size; i++) // Loop through each row
                {
                    delete[] matrix[i]; // Delete each row array
                }
                delete[] matrix; // Delete the array of pointers
            }
        }

        /**
         * @brief Assignment operator
         * @param other The matrix to assign from
         * @return Reference to this matrix after assignment
         */
        SquareMat &operator=(const SquareMat &other); // Declaration of assignment operator

        /**
         * @brief Addition operator for matrices
         * @param other Matrix to add to this matrix
         * @return New matrix containing the sum
         * @throws std::invalid_argument if matrix sizes don't match
         */
        SquareMat operator+(const SquareMat &other) const // Addition operator overload
        {
            if (size != other.size) // Check if matrices have same size
            {
                throw std::invalid_argument("Matrix sizes must match"); // Throw exception if sizes don't match
            }
            SquareMat result(size);           // Create result matrix of same size
            for (size_t i = 0; i < size; i++) // Loop through rows
            {
                for (size_t j = 0; j < size; j++) // Loop through columns
                {
                    result.matrix[i][j] = matrix[i][j] + other.matrix[i][j]; // Add corresponding elements
                }
            }
            return result; // Return the resulting matrix
        }

        /**
         * @brief Subtraction operator for matrices
         * @param other Matrix to subtract from this matrix
         * @return New matrix containing the difference
         * @throws std::invalid_argument if matrix sizes don't match
         */
        SquareMat operator-(const SquareMat &other) const // Subtraction operator overload
        {
            if (size != other.size) // Check if matrices have same size
            {
                throw std::invalid_argument("Matrix sizes must match"); // Throw exception if sizes don't match
            }
            SquareMat result(size);           // Create result matrix of same size
            for (size_t i = 0; i < size; i++) // Loop through rows
            {
                for (size_t j = 0; j < size; j++) // Loop through columns
                {
                    result.matrix[i][j] = matrix[i][j] - other.matrix[i][j]; // Subtract corresponding elements
                }
            }
            return result; // Return the resulting matrix
        }

        /**
         * @brief Unary minus operator (negation)
         * @return New matrix with negated elements
         */
        SquareMat operator-() const // Unary minus operator overload
        {
            SquareMat result(size);           // Create result matrix of same size
            for (size_t i = 0; i < size; i++) // Loop through rows
            {
                for (size_t j = 0; j < size; j++) // Loop through columns
                {
                    result.matrix[i][j] = -matrix[i][j]; // Negate each element
                }
            }
            return result; // Return the resulting matrix
        }

        /**
         * @brief Matrix multiplication operator
         * @param other Matrix to multiply with this matrix
         * @return New matrix containing the product
         * @throws std::invalid_argument if matrix sizes don't match
         */
        SquareMat operator*(const SquareMat &other) const; // Declaration of matrix multiplication operator

        /**
         * @brief Scalar multiplication operator (right side)
         * @param scalar Value to multiply matrix elements by
         * @return New matrix with scaled elements
         */
        SquareMat operator*(double scalar) const; // Declaration of scalar multiplication operator

        /**
         * @brief Scalar multiplication operator (left side)
         * @param scalar Value to multiply matrix elements by
         * @param mat Matrix to multiply
         * @return New matrix with scaled elements
         */
        friend SquareMat operator*(double scalar, const SquareMat &mat); // Declaration of friend function for left scalar multiplication

        /**
         * @brief Element-wise multiplication operator
         * @param other Matrix for element-wise multiplication
         * @return New matrix with element-wise product
         * @throws std::invalid_argument if matrix sizes don't match
         */
        SquareMat operator%(const SquareMat &other) const; // Declaration of element-wise multiplication operator

        /**
         * @brief Modulo operator with scalar
         * @param scalar Value to calculate modulo with
         * @return New matrix with modulo applied to each element
         * @throws std::invalid_argument if scalar is zero
         */
        SquareMat operator%(int scalar) const; // Declaration of modulo operator

        /**
         * @brief Division operator with scalar
         * @param scalar Value to divide matrix elements by
         * @return New matrix with divided elements
         * @throws std::invalid_argument if scalar is zero
         */
        SquareMat operator/(double scalar) const // Division operator overload
        {
            if (scalar == 0) // Check if scalar is zero
            {
                throw std::invalid_argument("Division by zero"); // Throw exception for division by zero
            }
            SquareMat result(size);           // Create result matrix of same size
            for (size_t i = 0; i < size; i++) // Loop through rows
            {
                for (size_t j = 0; j < size; j++) // Loop through columns
                {
                    result.matrix[i][j] = matrix[i][j] / scalar; // Divide each element by scalar
                }
            }
            return result; // Return the resulting matrix
        }

        /**
         * @brief Power operator
         * @param power The exponent to raise the matrix to
         * @return New matrix containing the result of matrix^power
         * @throws std::invalid_argument if power is negative
         */
        SquareMat operator^(int power) const; // Declaration of power operator

        /**
         * @brief Prefix increment operator
         * @return Reference to this matrix after incrementing all elements
         */
        SquareMat operator++()                // Prefix increment operator overload
        {                                     // prefix increment
            for (size_t i = 0; i < size; i++) // Loop through rows
            {
                for (size_t j = 0; j < size; j++) // Loop through columns
                {
                    matrix[i][j]++; // Increment each element
                }
            }
            return *this; // return the modified matrix
        }

        /**
         * @brief Postfix increment operator
         * @return Copy of the matrix before incrementing
         */
        SquareMat operator++(int)  // Postfix increment operator overload
        {                          // postfix increment
            SquareMat temp(*this); // Create a copy of current matrix
            ++(*this);             // Call prefix increment on this matrix
            return temp;           // return the original matrix
        }

        /**
         * @brief Prefix decrement operator
         * @return Reference to this matrix after decrementing all elements
         */
        SquareMat operator--()                // Prefix decrement operator overload
        {                                     // prefix decrement
            for (size_t i = 0; i < size; i++) // Loop through rows
            {
                for (size_t j = 0; j < size; j++) // Loop through columns
                {
                    matrix[i][j]--; // Decrement each element
                }
            }
            return *this; // return the modified matrix
        }

        /**
         * @brief Postfix decrement operator
         * @return Copy of the matrix before decrementing
         */
        SquareMat operator--(int)  // Postfix decrement operator overload
        {                          // postfix decrement
            SquareMat temp(*this); // Create a copy of current matrix
            --(*this);             // Call prefix decrement on this matrix
            return temp;           // return the original matrix
        }

        /**
         * @brief Transpose operator
         * @return New matrix that is the transpose of this matrix
         */
        SquareMat operator~() const           // Transpose operator overload
        {                                     // transpose
            SquareMat result(size);           // Create result matrix of same size
            for (size_t i = 0; i < size; i++) // Loop through rows
            {
                for (size_t j = 0; j < size; j++) // Loop through columns
                {
                    result.matrix[j][i] = matrix[i][j]; // Swap row and column indices
                }
            }
            return result; // Return the transposed matrix
        }

        /**
         * @brief Array subscript operator (non-const version)
         * @param index Row index
         * @return Pointer to the row for further indexing
         * @throws std::out_of_range if index is out of bounds
         */
        double *operator[](size_t index) // Non-const subscript operator overload
        {
            if (index >= size) // Check if index is out of bounds
            {
                throw std::out_of_range("Index out of bounds"); // Throw exception for invalid index
            }
            return matrix[index]; // Return pointer to the row
        }

        /**
         * @brief Array subscript operator (const version)
         * @param index Row index
         * @return Const pointer to the row for further indexing
         * @throws std::out_of_range if index is out of bounds
         */
        const double *operator[](size_t index) const // Const subscript operator overload
        {
            if (index >= size) // Check if index is out of bounds
            {
                throw std::out_of_range("Index out of bounds"); // Throw exception for invalid index
            }
            return matrix[index]; // Return const pointer to the row
        }

        /**
         * @brief Get the size of the matrix
         * @return Size of the matrix (number of rows/columns)
         */
        size_t getSize() const { return size; } // Getter method for matrix size

        /**
         * @brief Calculate sum of all elements in the matrix
         * @return Sum of all matrix elements
         */
        double sum() const // Method to calculate sum of all elements
        {
            double sum = 0;                   // Initialize sum to zero
            for (size_t i = 0; i < size; i++) // Loop through rows
            {
                for (size_t j = 0; j < size; j++) // Loop through columns
                {
                    sum += matrix[i][j]; // Add each element to sum
                }
            }
            return sum; // Return the total sum
        }

        /**
         * @brief Equality comparison operator
         * @param other Matrix to compare with
         * @return true if matrices have equal sums, false otherwise
         */
        bool operator==(const SquareMat &other) const // Equality operator overload
        {
            return sum() == other.sum(); // Compare sums of matrices
        }

        /**
         * @brief Inequality comparison operator
         * @param other Matrix to compare with
         * @return true if matrices have different sums, false otherwise
         */
        bool operator!=(const SquareMat &other) const // Inequality operator overload
        {
            return !(sum() == other.sum()); // Negate equality comparison
        }

        /**
         * @brief Greater than comparison operator
         * @param other Matrix to compare with
         * @return true if this matrix has greater sum than other, false otherwise
         */
        bool operator>(const SquareMat &other) const // Greater than operator overload
        {
            return sum() > other.sum(); // Compare if this sum is greater
        }

        /**
         * @brief Less than comparison operator
         * @param other Matrix to compare with
         * @return true if this matrix has smaller sum than other, false otherwise
         */
        bool operator<(const SquareMat &other) const // Less than operator overload
        {
            return sum() < other.sum(); // Compare if this sum is smaller
        }

        /**
         * @brief Greater than or equal comparison operator
         * @param other Matrix to compare with
         * @return true if this matrix has greater or equal sum than other, false otherwise
         */
        bool operator>=(const SquareMat &other) const // Greater than or equal operator overload
        {
            return sum() >= other.sum(); // Compare if this sum is greater or equal
        }

        /**
         * @brief Less than or equal comparison operator
         * @param other Matrix to compare with
         * @return true if this matrix has smaller or equal sum than other, false otherwise
         */
        bool operator<=(const SquareMat &other) const // Less than or equal operator overload
        {
            return sum() <= other.sum(); // Compare if this sum is smaller or equal
        }

        /**
         * @brief Determinant operator
         * @return Determinant of the matrix
         */
        double operator!() const; // Declaration of determinant operator

        /**
         * @brief Compound assignment addition operator
         * @param other Matrix to add to this matrix
         * @return Reference to this matrix after addition
         * @throws std::invalid_argument if matrix sizes don't match
         */
        SquareMat &operator+=(const SquareMat &other); // Declaration of compound addition operator

        /**
         * @brief Compound assignment subtraction operator
         * @param other Matrix to subtract from this matrix
         * @return Reference to this matrix after subtraction
         * @throws std::invalid_argument if matrix sizes don't match
         */
        SquareMat &operator-=(const SquareMat &other); // Declaration of compound subtraction operator

        /**
         * @brief Compound assignment matrix multiplication operator
         * @param other Matrix to multiply with this matrix
         * @return Reference to this matrix after multiplication
         * @throws std::invalid_argument if matrix sizes don't match
         */
        SquareMat &operator*=(const SquareMat &other); // Declaration of compound matrix multiplication operator

        /**
         * @brief Compound assignment scalar multiplication operator
         * @param scalar Value to multiply matrix elements by
         * @return Reference to this matrix after multiplication
         */
        SquareMat &operator*=(double scalar); // Declaration of compound scalar multiplication operator

        /**
         * @brief Compound assignment division operator
         * @param scalar Value to divide matrix elements by
         * @return Reference to this matrix after division
         * @throws std::invalid_argument if scalar is zero
         */
        SquareMat &operator/=(double scalar); // Declaration of compound division operator

        /**
         * @brief Compound assignment element-wise multiplication operator
         * @param other Matrix for element-wise multiplication
         * @return Reference to this matrix after multiplication
         * @throws std::invalid_argument if matrix sizes don't match
         */
        SquareMat &operator%=(const SquareMat &other); // Declaration of compound element-wise multiplication operator

        /**
         * @brief Compound assignment modulo operator
         * @param scalar Value to calculate modulo with
         * @return Reference to this matrix after modulo operation
         * @throws std::invalid_argument if scalar is zero
         */
        SquareMat &operator%=(int scalar); // Declaration of compound modulo operator

        /**
         * @brief Output stream operator for SquareMat
         * @param os Output stream
         * @param mat Matrix to output
         * @return Reference to output stream
         */
        friend std::ostream &operator<<(std::ostream &os, const SquareMat &mat); // Declaration of friend output stream operator
    };
} // End of namespace
