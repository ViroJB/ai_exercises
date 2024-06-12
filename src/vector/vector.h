#pragma once

#include <iostream>
#include <string>
#include <assert.h>
#include <fmt/core.h>

class Vector {
   public:
    Vector(int size);
    ~Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);

    void Set(int index, double value);
    double Get(int index) const;
    int Size() const;
    Vector Transpose() const;

    Vector operator+(const Vector& other);
    Vector operator-(const Vector& other);

    Vector ElementwiseProduct(const Vector& other) const;
    double ScalarProduct(const Vector& other);
    Vector CrossProduct(const Vector& other);

    std::string ToString() const;

   private:
    int m_size;
    double* m_data;
};