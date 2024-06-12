#include "perceptron.h"

Perceptron::Perceptron(int input_size) : m_weights(input_size), m_input_size(input_size) {
    // initialize weights with random values
    for (int i = 0; i < m_input_size; i++) {
        m_weights.Set(i, (rand() % 100) / 100.0 - 0.5);
    }

    m_bias = 0.0;
}

void Perceptron::SetWeights(const Vector& weights) {
    assert(weights.Size() == m_input_size);
    m_weights = weights;
}

void Perceptron::SetBias(double bias) {
    m_bias = bias;
}

const Vector& Perceptron::GetWeights() const {
    return m_weights;
}

double Perceptron::GetBias() const {
    return m_bias;
}

int Perceptron::GetInputSize() const {
    return m_input_size;
}

double Perceptron::Forward(const Vector& inputs) {
    assert(inputs.Size() == m_input_size);

    double z = m_weights.ScalarProduct(inputs) + m_bias;
    return Activate(z);
}

void Perceptron::Backward(const Vector& inputs, double delta, double learning_rate) {
    assert(inputs.Size() == m_input_size);
    for (int i = 0; i < m_input_size; i++) {
        double new_weight = m_weights.Get(i) + learning_rate * delta * inputs.Get(i);
        m_weights.Set(i, new_weight);
    }
    m_bias += learning_rate * delta;
}

double Perceptron::Activate(double z) {
    // sigmoid activation function
    return 1.0 / (1.0 + std::exp(-z));
}

Perceptron::~Perceptron() {
}