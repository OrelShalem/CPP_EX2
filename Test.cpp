// orel8155@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "squaremat.hpp"
#include <sstream>

using namespace squaremat;

/**
 * @file Test.cpp
 * @brief Unit tests for the SquareMat class
 *
 * This file contains a comprehensive set of unit tests for the SquareMat class,
 * testing all operations, functions, and error handling.
 */

/**
 * @brief Test basic matrix operations including construction and element access
 */
TEST_CASE("Matrix Operations Basic")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    // Test element access
    CHECK(m1[0][0] == 1);
    CHECK(m1[0][1] == 2);
    CHECK(m1[1][0] == 3);
    CHECK(m1[1][1] == 4);
}

/**
 * @brief Test matrix addition operation
 */
TEST_CASE("Matrix Addition")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    SquareMat m3 = m1 + m2;
    CHECK(m3[0][0] == 6);
    CHECK(m3[0][1] == 8);
    CHECK(m3[1][0] == 10);
    CHECK(m3[1][1] == 12);
}

/**
 * @brief Test matrix subtraction operation
 */
TEST_CASE("Matrix Subtraction")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    SquareMat m4 = m1 - m2;
    CHECK(m4[0][0] == -4);
    CHECK(m4[0][1] == -4);
    CHECK(m4[1][0] == -4);
    CHECK(m4[1][1] == -4);
}

/**
 * @brief Test matrix multiplication operation
 */
TEST_CASE("Matrix Multiplication")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    SquareMat m5 = m1 * m2;
    CHECK(m5[0][0] == 19);
    CHECK(m5[0][1] == 22);
    CHECK(m5[1][0] == 43);
    CHECK(m5[1][1] == 50);
}

/**
 * @brief Test scalar multiplication operation
 */
TEST_CASE("Matrix Scalar Multiplication")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m6 = m1 * 2;
    CHECK(m6[0][0] == 2);
    CHECK(m6[0][1] == 4);
    CHECK(m6[1][0] == 6);
    CHECK(m6[1][1] == 8);
}

/**
 * @brief Test matrix transpose operation
 */
TEST_CASE("Matrix Transpose")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m7 = ~m1;
    CHECK(m7[0][0] == 1);
    CHECK(m7[0][1] == 3);
    CHECK(m7[1][0] == 2);
    CHECK(m7[1][1] == 4);
}

/**
 * @brief Test increment and decrement operations (both prefix and postfix)
 */
TEST_CASE("Matrix Increment and Decrement")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    // prefix increment
    SquareMat m2 = ++m1;
    CHECK(m1[0][0] == 2);
    CHECK(m1[0][1] == 3);
    CHECK(m1[1][0] == 4);
    CHECK(m1[1][1] == 5);
    CHECK(m2[0][0] == 2);
    CHECK(m2[0][1] == 3);
    CHECK(m2[1][0] == 4);
    CHECK(m2[1][1] == 5);

    // postfix increment
    SquareMat m3 = m1++;
    CHECK(m1[0][0] == 3);
    CHECK(m1[0][1] == 4);
    CHECK(m1[1][0] == 5);
    CHECK(m1[1][1] == 6);
    CHECK(m3[0][0] == 2);
    CHECK(m3[0][1] == 3);
    CHECK(m3[1][0] == 4);
    CHECK(m3[1][1] == 5);

    // prefix decrement
    SquareMat m4 = --m1;
    CHECK(m1[0][0] == 2);
    CHECK(m1[0][1] == 3);
    CHECK(m1[1][0] == 4);
    CHECK(m1[1][1] == 5);
    CHECK(m4[0][0] == 2);
    CHECK(m4[0][1] == 3);
    CHECK(m4[1][0] == 4);
    CHECK(m4[1][1] == 5);

    // postfix decrement
    SquareMat m5 = m1--;
    CHECK(m1[0][0] == 1);
    CHECK(m1[0][1] == 2);
    CHECK(m1[1][0] == 3);
    CHECK(m1[1][1] == 4);
    CHECK(m5[0][0] == 2);
    CHECK(m5[0][1] == 3);
    CHECK(m5[1][0] == 4);
    CHECK(m5[1][1] == 5);
}

/**
 * @brief Test comparison operations based on matrix element sums
 */
TEST_CASE("Matrix Comparison")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    // Sum: 10

    SquareMat m2(2);
    m2[0][0] = 2;
    m2[0][1] = 3;
    m2[1][0] = 1;
    m2[1][1] = 4;
    // Sum: 10

    SquareMat m3(2);
    m3[0][0] = 5;
    m3[0][1] = 5;
    m3[1][0] = 5;
    m3[1][1] = 5;
    // Sum: 20

    CHECK(m1 == m2);
    CHECK_FALSE(m1 == m3);

    CHECK_FALSE(m1 != m2);
    CHECK(m1 != m3);

    CHECK(m1 < m3);
    CHECK(m3 > m1);
    CHECK(m1 <= m2);
    CHECK(m1 <= m3);
    CHECK(m3 >= m1);
    CHECK(m1 >= m2);
}

/**
 * @brief Test compound assignment addition operation
 */
TEST_CASE("Matrix Compound Assignment +=")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    // +=
    SquareMat m3 = m1;
    m3 += m2;
    CHECK(m3[0][0] == 6);
    CHECK(m3[0][1] == 8);
    CHECK(m3[1][0] == 10);
    CHECK(m3[1][1] == 12);
}

/**
 * @brief Test compound assignment subtraction operation
 */
TEST_CASE("Matrix Compound Assignment -=")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    // -=
    SquareMat m4 = m1;
    m4 -= m2;
    CHECK(m4[0][0] == -4);
    CHECK(m4[0][1] == -4);
    CHECK(m4[1][0] == -4);
    CHECK(m4[1][1] == -4);
}

/**
 * @brief Test compound assignment matrix multiplication operation
 */
TEST_CASE("Matrix Compound Assignment *= (matrix)")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    // *=
    SquareMat m5 = m1;
    m5 *= m2;
    CHECK(m5[0][0] == 19);
    CHECK(m5[0][1] == 22);
    CHECK(m5[1][0] == 43);
    CHECK(m5[1][1] == 50);
}

/**
 * @brief Test compound assignment scalar multiplication operation
 */
TEST_CASE("Matrix Compound Assignment *= (scalar)")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    // *= scalar
    SquareMat m6 = m1;
    m6 *= 2;
    CHECK(m6[0][0] == 2);
    CHECK(m6[0][1] == 4);
    CHECK(m6[1][0] == 6);
    CHECK(m6[1][1] == 8);
}

/**
 * @brief Test compound assignment division operation
 */
TEST_CASE("Matrix Compound Assignment /=")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    // /=
    SquareMat m7 = m1;
    m7 /= 2;
    CHECK(m7[0][0] == 0.5);
    CHECK(m7[0][1] == 1);
    CHECK(m7[1][0] == 1.5);
    CHECK(m7[1][1] == 2);
}

/**
 * @brief Test compound assignment element-wise multiplication operation
 */
TEST_CASE("Matrix Compound Assignment %= (matrix)")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    // %= matrix
    SquareMat m8 = m1;
    m8 %= m2;
    CHECK(m8[0][0] == 5);
    CHECK(m8[0][1] == 12);
    CHECK(m8[1][0] == 21);
    CHECK(m8[1][1] == 32);
}

/**
 * @brief Test compound assignment modulo operation
 */
TEST_CASE("Matrix Compound Assignment %= (scalar)")
{
    SquareMat m2(2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;

    // %= scalar
    SquareMat m9 = m2;
    m9 %= 4;
    CHECK(m9[0][0] == 1);
    CHECK(m9[0][1] == 2);
    CHECK(m9[1][0] == 3);
    CHECK(m9[1][1] == 0);
}

/**
 * @brief Test array access and exception handling for out-of-bounds access
 */
TEST_CASE("Matrix Access and Exceptions")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    CHECK(m1[0][0] == 1);
    CHECK(m1[0][1] == 2);
    CHECK(m1[1][0] == 3);
    CHECK(m1[1][1] == 4);

    // Test exception handling for out-of-bounds row access
    bool caught_exception = false;
    try
    {
        double *row = m1[2]; // Attempt to access out-of-bounds row
        (void)row;           // Prevent unused value warning
    }
    catch (const std::out_of_range &)
    {
        caught_exception = true;
    }
    CHECK(caught_exception);
}

/**
 * @brief Test determinant calculation for different matrix sizes
 */
TEST_CASE("Matrix Determinant")
{
    SquareMat m1(2);
    m1[0][0] = 4;
    m1[0][1] = 3;
    m1[1][0] = 2;
    m1[1][1] = 1;

    CHECK(!m1 == 4 * 1 - 3 * 2);

    SquareMat m2(3);
    m2[0][0] = 1;
    m2[0][1] = 2;
    m2[0][2] = 3;
    m2[1][0] = 4;
    m2[1][1] = 5;
    m2[1][2] = 6;
    m2[2][0] = 7;
    m2[2][1] = 8;
    m2[2][2] = 9;

    CHECK(!m2 == 0);

    SquareMat m3(3);
    m3[0][0] = 2;
    m3[0][1] = -3;
    m3[0][2] = 1;
    m3[1][0] = 2;
    m3[1][1] = 0;
    m3[1][2] = -1;
    m3[2][0] = 1;
    m3[2][1] = 4;
    m3[2][2] = 5;

    CHECK(!m3 == 49);
}

/**
 * @brief Test handling of invalid operations and exceptions
 */
TEST_CASE("Matrix Invalid Operations")
{
    SquareMat m1(2);
    SquareMat m2(3);

    CHECK_THROWS_AS(m1 + m2, std::invalid_argument);
    CHECK_THROWS_AS(m1 - m2, std::invalid_argument);
    CHECK_THROWS_AS(m1 * m2, std::invalid_argument);
    CHECK_THROWS_AS(m1 % m2, std::invalid_argument);

    CHECK_THROWS_AS(m1 / 0, std::invalid_argument);
    CHECK_THROWS_AS(m1 % 0, std::invalid_argument);

    CHECK_THROWS_AS(m1 ^ -1, std::invalid_argument);
}

/**
 * @brief Test output stream operator for matrices
 */
TEST_CASE("Matrix Output Stream")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    std::ostringstream oss;
    oss << m1;

    std::string expected = "1\t2\t\n3\t4\t\n";
    CHECK(oss.str() == expected);
}

/**
 * @brief Test matrix power operations for different exponents
 */
TEST_CASE("Matrix Power")
{
    SquareMat m1(2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;

    // Power 0
    SquareMat m0 = m1 ^ 0;
    CHECK(m0[0][0] == 1);
    CHECK(m0[0][1] == 0);
    CHECK(m0[1][0] == 0);
    CHECK(m0[1][1] == 1);

    // Power 1
    SquareMat m1p = m1 ^ 1;
    CHECK(m1p[0][0] == 1);
    CHECK(m1p[0][1] == 2);
    CHECK(m1p[1][0] == 3);
    CHECK(m1p[1][1] == 4);

    // Power 2
    SquareMat m2p = m1 ^ 2;
    CHECK(m2p[0][0] == 7);
    CHECK(m2p[0][1] == 10);
    CHECK(m2p[1][0] == 15);
    CHECK(m2p[1][1] == 22);
}