#pragma once

#include <vector>
#include <string>


class Matrix {
   public:
    Matrix(int rows, int cols);
    ~Matrix();
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    void Set(int row, int col, double value);
    double Get(int row, int col) const;

    Matrix Transpose() const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    std::string ToString() const;

   private:
    int m_rows;
    int m_cols;
    std::vector<std::vector<double>> m_data;
};