#include "vector.h"

Vector::Vector(int size) : m_size(size) {
    m_data = new double[size];
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = 0.0;  
    }
}

Vector::Vector(const Vector& other) : m_size(other.m_size) {
    m_data = new double[m_size];
    for (int i = 0; i < m_size; i++) {
        m_data[i] = other.m_data[i];
    }
}

Vector Vector::Transpose() const {
    Vector result(m_size);
    for (int i = 0; i < m_size; i++) {
        result.Set(i, m_data[i]);
    }

    return result;
}

double Vector::ScalarProduct(const Vector& other) {
    assert(m_size == other.m_size);

    double result = 0;
    for (int i = 0; i < m_size; i++) {
        result += m_data[i] * other.m_data[i];
    }

    return result;
}

Vector Vector::ElementwiseProduct(const Vector& other) const {
    assert(m_size == other.m_size);

    Vector result(m_size);
    for (size_t i = 0; i < m_size; i++) {
        result.Set(i, m_data[i] * other.m_data[i]);
    }

    return result;
}

Vector Vector::CrossProduct(const Vector& other) {
    assert(m_size == 3 && other.m_size == 3);

    Vector result(3);
    result.Set(0, m_data[1] * other.m_data[2] - m_data[2] * other.m_data[1]);
    result.Set(1, m_data[2] * other.m_data[0] - m_data[0] * other.m_data[2]);
    result.Set(2, m_data[0] * other.m_data[1] - m_data[1] * other.m_data[0]);

    return result;
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }

    delete[] m_data;
    m_size = other.m_size;
    m_data = new double[m_size];
    for (int i = 0; i < m_size; i++) {
        m_data[i] = other.m_data[i];
    }

    return *this;
}

Vector Vector::operator+(const Vector& other) {
    assert(m_size == other.m_size);

    Vector result(m_size);
    for (int i = 0; i < m_size; i++) {
        result.Set(i, m_data[i] + other.m_data[i]);
    }
    return result;
}

Vector Vector::operator-(const Vector& other) {
    assert(m_size == other.m_size);

    Vector result(m_size);
    for (int i = 0; i < m_size; i++) {
        result.Set(i, m_data[i] - other.m_data[i]);
    }
    return result;
}

void Vector::Set(int index, double value) {
    m_data[index] = value;
}

double Vector::Get(int index) const {
    return m_data[index];
}

int Vector::Size() const {
    return m_size;
}

Vector::~Vector() {
    delete[] m_data;
}

std::string Vector::ToString() const {
    std::string result = "[";
    for (int i = 0; i < m_size; i++) {
        result += std::to_string(m_data[i]);
        if (i < m_size - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}