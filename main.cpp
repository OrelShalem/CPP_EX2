// orel8155@gmail.com
#include "squaremat.hpp"

using namespace squaremat;

/**
 * @file main.cpp
 * @brief Main program demonstrating the usage of the SquareMat class
 *
 * This program demonstrates all operations and functionality provided by the SquareMat class,
 * including basic arithmetic, matrix operations, comparison operations, and more.
 */

int main()
{
    try
    {
        // Create and initialize matrices
        SquareMat mat1(3);
        mat1[0][0] = 1;
        mat1[0][1] = 2;
        mat1[0][2] = 3;
        mat1[1][0] = 4;
        mat1[1][1] = 5;
        mat1[1][2] = 6;
        mat1[2][0] = 7;
        mat1[2][1] = 8;
        mat1[2][2] = 9;

        std::cout << "Matrix 1:" << std::endl
                  << mat1 << std::endl;

        SquareMat mat2(3);
        mat2[0][0] = 9;
        mat2[0][1] = 8;
        mat2[0][2] = 7;
        mat2[1][0] = 6;
        mat2[1][1] = 5;
        mat2[1][2] = 4;
        mat2[2][0] = 3;
        mat2[2][1] = 2;
        mat2[2][2] = 1;

        std::cout << "Matrix 2:" << std::endl
                  << mat2 << std::endl;

        // Basic arithmetic operations
        std::cout << "Sum of matrices:" << std::endl;
        SquareMat sum = mat1 + mat2;
        std::cout << sum << std::endl;

        std::cout << "Difference of matrices:" << std::endl;
        SquareMat diff = mat1 - mat2;
        std::cout << diff << std::endl;

        std::cout << "Product of matrices:" << std::endl;
        SquareMat product = mat1 * mat2;
        std::cout << product << std::endl;

        // Scalar operations
        std::cout << "Scalar product of matrices:" << std::endl;
        SquareMat scalar = mat1 * 2;
        std::cout << scalar << std::endl;

        std::cout << "Left scalar product:" << std::endl;
        SquareMat leftScalar = 3 * mat1;
        std::cout << leftScalar << std::endl;

        // Transpose operation
        std::cout << "Transpose of matrix 1:" << std::endl;
        SquareMat transpose = ~mat1;
        std::cout << transpose << std::endl;

        // Determinant calculation
        std::cout << "Determinant of matrix 1:" << !mat1 << std::endl;

        // Unary negation
        std::cout << "Negation of matrix 1:" << std::endl;
        SquareMat negation = -mat1;
        std::cout << negation << std::endl;

        // Comparison operations
        std::cout << "Comparison of matrices by sum of elements:" << std::endl;
        std::cout << "Are matrix 1 and matrix 2 equal? " << (mat1 == mat2 ? "Yes" : "No") << std::endl;
        std::cout << "Is matrix 1 greater than matrix 2? " << (mat1 > mat2 ? "Yes" : "No") << std::endl;
        std::cout << "Is matrix 1 less than matrix 2? " << (mat1 < mat2 ? "Yes" : "No") << std::endl;
        std::cout << "Is matrix 1 greater than or equal to matrix 2? " << (mat1 >= mat2 ? "Yes" : "No") << std::endl;
        std::cout << "Is matrix 1 less than or equal to matrix 2? " << (mat1 <= mat2 ? "Yes" : "No") << std::endl;
        std::cout << "Are matrix 1 and matrix 2 not equal? " << (mat1 != mat2 ? "Yes" : "No") << std::endl;

        // Power operations
        std::cout << "Matrix 1 to the power of 0:" << std::endl;
        SquareMat power0 = mat1 ^ 0;
        std::cout << power0 << std::endl;

        std::cout << "Matrix 1 to the power of 1:" << std::endl;
        SquareMat power1 = mat1 ^ 1;
        std::cout << power1 << std::endl;

        std::cout << "Matrix 1 to the power of 2:" << std::endl;
        SquareMat power2 = mat1 ^ 2;
        std::cout << power2 << std::endl;

        // Division operation
        std::cout << "Division by scalar:" << std::endl;
        SquareMat division = mat1 / 2;
        std::cout << division << std::endl;

        // Element-wise operations
        std::cout << "Element-wise multiplication:" << std::endl;
        SquareMat elementMult = mat1 % mat2;
        std::cout << elementMult << std::endl;

        // Modulo operation
        std::cout << "Modulo with scalar (4):" << std::endl;
        SquareMat modulo = mat1 % 4;
        std::cout << modulo << std::endl;

        // Testing compound assignment operators
        std::cout << "Testing compound operators:" << std::endl;

        SquareMat compoundTest(2);
        compoundTest[0][0] = 1;
        compoundTest[0][1] = 2;
        compoundTest[1][0] = 3;
        compoundTest[1][1] = 4;

        SquareMat other(2);
        other[0][0] = 5;
        other[0][1] = 6;
        other[1][0] = 7;
        other[1][1] = 8;

        std::cout << "Original matrix:" << std::endl
                  << compoundTest << std::endl;

        // Testing compound addition
        compoundTest += other;
        std::cout << "After +=:" << std::endl
                  << compoundTest << std::endl;

        // Testing compound subtraction
        compoundTest -= other;
        std::cout << "After -=:" << std::endl
                  << compoundTest << std::endl;

        // Testing compound matrix multiplication
        compoundTest *= other;
        std::cout << "After *= (matrix):" << std::endl
                  << compoundTest << std::endl;

        // Testing compound scalar multiplication
        compoundTest *= 2;
        std::cout << "After *= (scalar):" << std::endl
                  << compoundTest << std::endl;

        // Testing compound division
        compoundTest /= 2;
        std::cout << "After /=:" << std::endl
                  << compoundTest << std::endl;

        // Testing compound element-wise multiplication
        compoundTest %= other;
        std::cout << "After %= (matrix):" << std::endl
                  << compoundTest << std::endl;

        // Testing compound modulo
        compoundTest %= 3;
        std::cout << "After %= (scalar):" << std::endl
                  << compoundTest << std::endl;

        // Increment and decrement operations
        std::cout << "Incrementing all elements of matrix 1:" << std::endl;
        SquareMat inc = ++mat1;
        std::cout << inc << std::endl;

        std::cout << "Decrementing all elements of matrix 1:" << std::endl;
        SquareMat dec = --mat1;
        std::cout << dec << std::endl;

        // Postfix increment and decrement
        std::cout << "Postfix increment:" << std::endl;
        SquareMat postInc = mat1++;
        std::cout << "Original value returned: " << std::endl
                  << postInc << std::endl;
        std::cout << "New value of matrix: " << std::endl
                  << mat1 << std::endl;

        std::cout << "Postfix decrement:" << std::endl;
        SquareMat postDec = mat1--;
        std::cout << "Original value returned: " << std::endl
                  << postDec << std::endl;
        std::cout << "New value of matrix: " << std::endl
                  << mat1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}