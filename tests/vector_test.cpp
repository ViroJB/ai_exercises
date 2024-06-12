#include "gtest/gtest.h"

#include "../src/vector/vector.h"

TEST(VectorTest, ScalarProduct) {
    Vector v1(3);
    v1.Set(0, 1);
    v1.Set(1, 2);
    v1.Set(2, 3);

    Vector v2(3);
    v2.Set(0, 4);
    v2.Set(1, 5);
    v2.Set(2, 6);

    double result = v1.ScalarProduct(v2);
    ASSERT_EQ(result, 32);
}

TEST(VectorTest, CrossProduct) {
    Vector v1(3);
    v1.Set(0, 1);
    v1.Set(1, 2);
    v1.Set(2, 3);

    Vector v2(3);
    v2.Set(0, 4);
    v2.Set(1, 5);
    v2.Set(2, 6);

    Vector result = v1.CrossProduct(v2);
    ASSERT_EQ(result.Get(0), -3);
    ASSERT_EQ(result.Get(1), 6);
    ASSERT_EQ(result.Get(2), -3);
}

TEST(VectorTest, Add) {
    Vector v1(3);
    v1.Set(0, 1);
    v1.Set(1, 2);
    v1.Set(2, 3);

    Vector v2(3);
    v2.Set(0, 4);
    v2.Set(1, 5);
    v2.Set(2, 6);

    Vector result = v1 + v2;
    ASSERT_EQ(result.Get(0), 5);
    ASSERT_EQ(result.Get(1), 7);
    ASSERT_EQ(result.Get(2), 9);
}

TEST(VectorTest, Subtract) {
    Vector v1(3);
    v1.Set(0, 1);
    v1.Set(1, 2);
    v1.Set(2, 3);

    Vector v2(3);
    v2.Set(0, 4);
    v2.Set(1, 5);
    v2.Set(2, 6);

    Vector result = v1 - v2;
    ASSERT_EQ(result.Get(0), -3);
    ASSERT_EQ(result.Get(1), -3);
    ASSERT_EQ(result.Get(2), -3);
}

TEST(VectorTest, CopyConstructor) {
    Vector v1(3);
    v1.Set(0, 1);
    v1.Set(1, 2);
    v1.Set(2, 3);

    Vector v2 = v1;
    ASSERT_EQ(v2.Get(0), 1);
    ASSERT_EQ(v2.Get(1), 2);
    ASSERT_EQ(v2.Get(2), 3);
}

TEST(VectorTest, AssignmentOperator) {
    Vector v1(3);
    v1.Set(0, 1);
    v1.Set(1, 2);
    v1.Set(2, 3);

    Vector v2(3);
    v2.Set(0, 4);
    v2.Set(1, 5);
    v2.Set(2, 6);

    v2 = v1;
    ASSERT_EQ(v2.Get(0), 1);
    ASSERT_EQ(v2.Get(1), 2);
    ASSERT_EQ(v2.Get(2), 3);
}