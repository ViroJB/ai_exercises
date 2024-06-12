#include <gtest/gtest.h>

#include "../src/matrix/matrix.h"

TEST(MatrixTest, Transpose) {
    Matrix m(2, 3);
    m.Set(0, 0, 1);
    m.Set(0, 1, 2);
    m.Set(0, 2, 3);
    m.Set(1, 0, 4);
    m.Set(1, 1, 5);
    m.Set(1, 2, 6);

    Matrix result = m.Transpose();
    ASSERT_EQ(result.Get(0, 0), 1);
    ASSERT_EQ(result.Get(0, 1), 4);
    ASSERT_EQ(result.Get(1, 0), 2);
    ASSERT_EQ(result.Get(1, 1), 5);
    ASSERT_EQ(result.Get(2, 0), 3);
    ASSERT_EQ(result.Get(2, 1), 6);
}

TEST(MatrixTest, Add) {
    Matrix m1(2, 2);
    m1.Set(0, 0, 1);
    m1.Set(0, 1, 2);
    m1.Set(1, 0, 3);
    m1.Set(1, 1, 4);

    Matrix m2(2, 2);
    m2.Set(0, 0, 5);
    m2.Set(0, 1, 6);
    m2.Set(1, 0, 7);
    m2.Set(1, 1, 8);

    Matrix result = m1 + m2;
    ASSERT_EQ(result.Get(0, 0), 6);
    ASSERT_EQ(result.Get(0, 1), 8);
    ASSERT_EQ(result.Get(1, 0), 10);
    ASSERT_EQ(result.Get(1, 1), 12);
}

TEST(MatrixTest, Subtract) {
    Matrix m1(2, 2);
    m1.Set(0, 0, 1);
    m1.Set(0, 1, 2);
    m1.Set(1, 0, 3);
    m1.Set(1, 1, 4);

    Matrix m2(2, 2);
    m2.Set(0, 0, 5);
    m2.Set(0, 1, 6);
    m2.Set(1, 0, 7);
    m2.Set(1, 1, 8);

    Matrix result = m1 - m2;
    ASSERT_EQ(result.Get(0, 0), -4);
    ASSERT_EQ(result.Get(0, 1), -4);
    ASSERT_EQ(result.Get(1, 0), -4);
    ASSERT_EQ(result.Get(1, 1), -4);
}

TEST(MatrixTest, Multiply) {
    Matrix m1(2, 3);
    m1.Set(0, 0, 1);
    m1.Set(0, 1, 2);
    m1.Set(0, 2, 3);
    m1.Set(1, 0, 4);
    m1.Set(1, 1, 5);
    m1.Set(1, 2, 6);

    Matrix m2(3, 2);
    m2.Set(0, 0, 7);
    m2.Set(0, 1, 8);
    m2.Set(1, 0, 9);
    m2.Set(1, 1, 10);
    m2.Set(2, 0, 11);
    m2.Set(2, 1, 12);

    Matrix result = m1 * m2;
    ASSERT_EQ(result.Get(0, 0), 58);
    ASSERT_EQ(result.Get(0, 1), 64);
    ASSERT_EQ(result.Get(1, 0), 139);
    ASSERT_EQ(result.Get(1, 1), 154);
}

TEST(MatrixTest, CopyConstructor) {
    Matrix m(2, 2);
    m.Set(0, 0, 1);
    m.Set(0, 1, 2);
    m.Set(1, 0, 3);
    m.Set(1, 1, 4);

    Matrix m2 = m;
    ASSERT_EQ(m2.Get(0, 0), 1);
    ASSERT_EQ(m2.Get(0, 1), 2);
    ASSERT_EQ(m2.Get(1, 0), 3);
    ASSERT_EQ(m2.Get(1, 1), 4);
}

TEST(MatrixTest, AssignmentOperator) {
    Matrix m1(2, 2);
    m1.Set(0, 0, 1);
    m1.Set(0, 1, 2);
    m1.Set(1, 0, 3);
    m1.Set(1, 1, 4);

    Matrix m2(2, 2);
    m2.Set(0, 0, 5);
    m2.Set(0, 1, 6);
    m2.Set(1, 0, 7);
    m2.Set(1, 1, 8);

    m2 = m1;
    ASSERT_EQ(m2.Get(0, 0), 1);
    ASSERT_EQ(m2.Get(0, 1), 2);
    ASSERT_EQ(m2.Get(1, 0), 3);
    ASSERT_EQ(m2.Get(1, 1), 4);
}