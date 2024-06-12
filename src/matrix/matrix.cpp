#include "matrix.h"

Matrix::Matrix(int rows, int cols) : m_rows(rows), m_cols(cols), m_data(rows, std::vector<double>(cols)) {
}

void Matrix::Set(int row, int col, double value) {
    m_data[row][col] = value;
}

double Matrix::Get(int row, int col) const {
    return m_data[row][col];
}

Matrix::Matrix(const Matrix& other) : m_rows(other.m_rows), m_cols(other.m_cols), m_data(other.m_data) {
}

Matrix Matrix::Transpose() const {
    Matrix result(m_cols, m_rows);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            result.Set(j, i, m_data[i][j]);
        }
    }
    return result;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }

    m_rows = other.m_rows;
    m_cols = other.m_cols;
    m_data = other.m_data;
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            result.Set(i, j, m_data[i][j] + other.Get(i, j));
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            result.Set(i, j, m_data[i][j] - other.Get(i, j));
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(m_rows, other.m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < other.m_cols; j++) {
            double sum = 0;
            for (int k = 0; k < m_cols; k++) {
                sum += m_data[i][k] * other.Get(k, j);
            }
            result.Set(i, j, sum);
        }
    }
    return result;
}

Matrix::~Matrix() {
}

std::string Matrix::ToString() const {
    std::string result = "";
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            result += std::to_string(m_data[i][j]) + " ";
        }
        result += "\n";
    }
    return result;
}