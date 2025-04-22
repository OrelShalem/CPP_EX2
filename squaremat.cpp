// orel8155@gmail.com - Email address of the author
#include "squaremat.hpp" // Include the header file for SquareMat class

namespace squaremat // Start of the squaremat namespace
{
    /**
     * @brief Matrix multiplication operator implementation
     * @param other Matrix to multiply with this matrix
     * @return New matrix containing the product
     * @throws std::invalid_argument if matrix sizes don't match
     */
    SquareMat SquareMat::operator*(const SquareMat &other) const // Matrix multiplication operator definition
    {
        if (size != other.size) // Check if matrices have compatible sizes
        {
            throw std::invalid_argument("Matrix sizes must match"); // Throw exception if sizes don't match
        }
        SquareMat result(size);           // Create result matrix with same size
        for (size_t i = 0; i < size; i++) // Loop through rows
        {
            for (size_t j = 0; j < size; j++) // Loop through columns
            {
                for (size_t k = 0; k < size; k++) // Loop for dot product calculation
                {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j]; // Accumulate dot product
                }
            }
        }
        return result; // Return the resulting matrix
    }

    /**
     * @brief Scalar multiplication operator (right side) implementation
     * @param scalar Value to multiply matrix elements by
     * @return New matrix with scaled elements
     */
    SquareMat SquareMat::operator*(double scalar) const // Scalar multiplication operator definition
    {
        SquareMat result(size);           // Create result matrix with same size
        for (size_t i = 0; i < size; i++) // Loop through rows
        {
            for (size_t j = 0; j < size; j++) // Loop through columns
            {
                result.matrix[i][j] = matrix[i][j] * scalar; // Multiply each element by scalar
            }
        }
        return result; // Return the resulting matrix
    }

    /**
     * @brief Scalar multiplication operator (left side) implementation
     * @param scalar Value to multiply matrix elements by
     * @param mat Matrix to multiply
     * @return New matrix with scaled elements
     */
    SquareMat operator*(double scalar, const SquareMat &mat) // Friend function for left scalar multiplication
    {
        return mat * scalar; // Reuse right scalar multiplication
    }

    /**
     * @brief Element-wise multiplication operator implementation
     * @param other Matrix for element-wise multiplication
     * @return New matrix with element-wise product
     * @throws std::invalid_argument if matrix sizes don't match
     */
    SquareMat SquareMat::operator%(const SquareMat &other) const // Element-wise multiplication operator definition
    {
        if (size != other.size) // Check if matrices have compatible sizes
        {
            throw std::invalid_argument("Matrix sizes must match"); // Throw exception if sizes don't match
        }
        SquareMat result(size); // Create result matrix with same size

        for (size_t i = 0; i < size; i++) // Loop through rows
        {
            for (size_t j = 0; j < size; j++) // Loop through columns
            {
                result.matrix[i][j] = matrix[i][j] * other.matrix[i][j]; // Multiply corresponding elements
            }
        }
        return result; // Return the resulting matrix
    }

    /**
     * @brief Modulo operator with scalar implementation
     * @param scalar Value to calculate modulo with
     * @return New matrix with modulo applied to each element
     * @throws std::invalid_argument if scalar is zero
     */
    SquareMat SquareMat::operator%(int scalar) const // Modulo operator definition
    {
        if (scalar == 0) // Check if scalar is zero
        {
            throw std::invalid_argument("Scalar must be non-zero"); // Throw exception if scalar is zero
        }
        SquareMat result(size);           // Create result matrix with same size
        for (size_t i = 0; i < size; i++) // Loop through rows
        {
            for (size_t j = 0; j < size; j++) // Loop through columns
            {
                result.matrix[i][j] = fmod(matrix[i][j], scalar); // Apply modulo to each element
            }
        }
        return result; // Return the resulting matrix
    }

    /**
     * @brief Power operator implementation
     * @param power The exponent to raise the matrix to
     * @return New matrix containing the result of matrix^power
     * @throws std::invalid_argument if power is negative
     */
    SquareMat SquareMat::operator^(int power) const // Power operator definition
    {
        if (power < 0) // Check if power is negative
        {
            throw std::invalid_argument("Power must be non-negative"); // Throw exception if power is negative
        }

        // Power 0 returns identity matrix
        if (power == 0) // Check if power is zero
        {
            SquareMat result(size);           // Create result matrix with same size
            for (size_t i = 0; i < size; i++) // Loop through diagonal elements
            {
                result.matrix[i][i] = 1; // Set diagonal elements to 1 (identity matrix)
            }
            return result; // Return identity matrix
        }

        // Power 1 returns a copy of the current matrix
        if (power == 1) // Check if power is one
        {
            return SquareMat(*this); // Return copy of current matrix
        }

        // Simple solution: multiply the matrix by itself 'power' times
        SquareMat result(*this); // Initialize result with current matrix

        for (int i = 1; i < power; i++) // Loop power-1 times
        {
            // Perform multiplication
            SquareMat temp = result * (*this); // Multiply result by original matrix

            // Manually copy the result to avoid using operator=
            for (size_t r = 0; r < size; r++) // Loop through rows
            {
                for (size_t c = 0; c < size; c++) // Loop through columns
                {
                    result.matrix[r][c] = temp.matrix[r][c]; // Copy each element
                }
            }
        }

        return result; // Return the resulting matrix
    }

    /**
     * @brief Determinant operator implementation
     * @return Determinant of the matrix
     */
    double SquareMat::operator!() const // Determinant operator definition
    {
        if (size == 1) // Base case: 1x1 matrix
        {
            return matrix[0][0]; // Return the single element
        }

        if (size == 2) // Base case: 2x2 matrix
        {
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]; // Use 2x2 determinant formula
        }

        double det = 0;                   // Initialize determinant to zero
        for (size_t j = 0; j < size; j++) // Loop through first row elements
        {
            SquareMat submat(size - 1);       // Create submatrix of size-1
            for (size_t i = 1; i < size; i++) // Loop through rows (skip first row)
            {
                size_t col_idx = 0;               // Initialize column index for submatrix
                for (size_t k = 0; k < size; k++) // Loop through columns
                {
                    if (k != j) // Skip the current column
                    {
                        submat.matrix[i - 1][col_idx] = matrix[i][k]; // Copy element to submatrix
                        col_idx++;                                    // Increment submatrix column index
                    }
                }
            }
            double sign = (j % 2 == 0) ? 1.0 : -1.0; // Determine sign based on column index
            det += sign * matrix[0][j] * (!submat);  // Add term to determinant (recursive call)
        }
        return det; // Return the calculated determinant
    }

    /**
     * @brief Assignment operator implementation
     * @param other The matrix to assign from
     * @return Reference to this matrix after assignment
     */
    SquareMat &SquareMat::operator=(const SquareMat &other) // Assignment operator definition
    {
        if (this == &other) // Check for self-assignment
        {
            return *this; // Return if self-assignment
        }

        // Free current resources
        for (size_t i = 0; i < size; i++) // Loop through current rows
        {
            delete[] matrix[i]; // Delete each row
        }
        delete[] matrix; // Delete the array of pointers

        // Allocate new resources
        size = other.size;           // Update size
        matrix = new double *[size]; // Allocate new array of pointers

        for (size_t i = 0; i < size; i++) // Loop through rows
        {
            matrix[i] = new double[size];     // Allocate new row
            for (size_t j = 0; j < size; j++) // Loop through columns
            {
                matrix[i][j] = other.matrix[i][j]; // Copy values from other matrix
            }
        }

        return *this; // Return reference to modified matrix
    }

    /**
     * @brief Compound assignment addition operator implementation
     * @param other Matrix to add to this matrix
     * @return Reference to this matrix after addition
     * @throws std::invalid_argument if matrix sizes don't match
     */
    SquareMat &SquareMat::operator+=(const SquareMat &other) // Compound addition operator definition
    {
        if (size != other.size) // Check if matrices have compatible sizes
        {
            throw std::invalid_argument("Matrix sizes must match"); // Throw exception if sizes don't match
        }
        for (size_t i = 0; i < size; i++) // Loop through rows
        {
            for (size_t j = 0; j < size; j++) // Loop through columns
            {
                matrix[i][j] += other.matrix[i][j]; // Add corresponding elements
            }
        }
        return *this; // Return reference to modified matrix
    }

    /**
     * @brief Compound assignment subtraction operator implementation
     * @param other Matrix to subtract from this matrix
     * @return Reference to this matrix after subtraction
     * @throws std::invalid_argument if matrix sizes don't match
     */
    SquareMat &SquareMat::operator-=(const SquareMat &other) // Compound subtraction operator definition
    {
        if (size != other.size) // Check if matrices have compatible sizes
        {
            throw std::invalid_argument("Matrix sizes must match"); // Throw exception if sizes don't match
        }
        for (size_t i = 0; i < size; i++) // Loop through rows
        {
            for (size_t j = 0; j < size; j++) // Loop through columns
            {
                matrix[i][j] -= other.matrix[i][j]; // Subtract corresponding elements
            }
        }
        return *this; // Return reference to modified matrix
    }

    /**
     * @brief Compound assignment matrix multiplication operator implementation
     * @param other Matrix to multiply with this matrix
     * @return Reference to this matrix after multiplication
     * @throws std::invalid_argument if matrix sizes don't match
     */
    SquareMat &SquareMat::operator*=(const SquareMat &other) // Compound multiplication operator definition
    {
        if (size != other.size) // Check if matrices have compatible sizes
        {
            throw std::invalid_argument("Matrix sizes must match"); // Throw exception if sizes don't match
        }

        SquareMat temp = *this * other; // Calculate product using regular multiplication

        // Free current resources
        for (size_t i = 0; i < size; i++) // Loop through rows
        {
            delete[] matrix[i]; // Delete each row
        }

        // Preserve size (since size doesn't change)

        // Allocate new rows
        for (size_t i = 0; i < size; i++) // Loop through rows
        {
            matrix[i] = new double[size]; // Allocate new row
            // Copy data from temporary result
            for (size_t j = 0; j < size; j++) // Loop through columns
            {
                matrix[i][j] = temp.matrix[i][j]; // Copy element from temporary result
            }
        }

        return *this; // Return reference to modified matrix
    }

    /**
     * @brief Compound assignment scalar multiplication operator implementation
     * @param scalar Value to multiply matrix elements by
     * @return Reference to this matrix after multiplication
     * @throws std::invalid_argument if scalar is zero
     */
    SquareMat &SquareMat::operator*=(double scalar) // Compound scalar multiplication operator definition
    {
        if (scalar == 0) // Check if scalar is zero
        {
            throw std::invalid_argument("Scalar must be non-zero"); // Throw exception if scalar is zero
        }
        for (size_t i = 0; i < size; i++) // Loop through rows
        {
            for (size_t j = 0; j < size; j++) // Loop through columns
            {
                matrix[i][j] *= scalar; // Multiply each element by scalar
            }
        }
        return *this; // Return reference to modified matrix
    }

    /**
     * @brief Compound assignment division operator implementation
     * @param scalar Value to divide matrix elements by
     * @return Reference to this matrix after division
     * @throws std::invalid_argument if scalar is zero
     */
    SquareMat &SquareMat::operator/=(double scalar) // Compound division operator definition
    {
        if (scalar == 0) // Check if scalar is zero
        {
            throw std::invalid_argument("Scalar must be non-zero"); // Throw exception if scalar is zero
        }
        for (size_t i = 0; i < size; i++) // Loop through rows
        {
            for (size_t j = 0; j < size; j++) // Loop through columns
            {
                matrix[i][j] /= scalar; // Divide each element by scalar
            }
        }
        return *this; // Return reference to modified matrix
    }

    /**
     * @brief Compound assignment element-wise multiplication operator implementation
     * @param other Matrix for element-wise multiplication
     * @return Reference to this matrix after multiplication
     * @throws std::invalid_argument if matrix sizes don't match
     */
    SquareMat &SquareMat::operator%=(const SquareMat &other) // Compound element-wise multiplication operator definition
    {
        if (size != other.size) // Check if matrices have compatible sizes
        {
            throw std::invalid_argument("Matrix sizes must match"); // Throw exception if sizes don't match
        }
        for (size_t i = 0; i < size; i++) // Loop through rows
        {
            for (size_t j = 0; j < size; j++) // Loop through columns
            {
                matrix[i][j] *= other.matrix[i][j]; // Multiply corresponding elements
            }
        }
        return *this; // Return reference to modified matrix
    }

    /**
     * @brief Compound assignment modulo operator implementation
     * @param scalar Value to calculate modulo with
     * @return Reference to this matrix after modulo operation
     * @throws std::invalid_argument if scalar is zero
     */
    SquareMat &SquareMat::operator%=(int scalar) // Compound modulo operator definition
    {
        if (scalar == 0) // Check if scalar is zero
        {
            throw std::invalid_argument("Scalar must be non-zero"); // Throw exception if scalar is zero
        }
        for (size_t i = 0; i < size; i++) // Loop through rows
        {
            for (size_t j = 0; j < size; j++) // Loop through columns
            {
                matrix[i][j] = fmod(matrix[i][j], scalar); // Apply modulo to each element
            }
        }
        return *this; // Return reference to modified matrix
    }

    /**
     * @brief Output stream operator for SquareMat implementation
     * @param os Output stream
     * @param mat Matrix to output
     * @return Reference to output stream
     */
    std::ostream &operator<<(std::ostream &os, const SquareMat &mat) // Output stream operator definition
    {
        for (size_t i = 0; i < mat.size; i++) // Loop through rows
        {
            for (size_t j = 0; j < mat.size; j++) // Loop through columns
            {
                os << mat.matrix[i][j] << "\t"; // Output element with tab separator
            }
            os << std::endl; // End line after each row
        }
        return os; // Return reference to output stream
    }
} // End of squaremat namespace