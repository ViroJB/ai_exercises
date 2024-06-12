#include "layer.h"

Layer::Layer(int input_size, int num_perceptrons) : m_input_size(input_size), m_num_perceptrons(num_perceptrons) {
    InitializePerceptrons();
}

Layer::~Layer() {}

void Layer::InitializePerceptrons() {
    for (int i = 0; i < m_num_perceptrons; i++) {
        m_perceptrons.emplace_back(Perceptron(m_input_size));
    }
}

const std::vector<Vector>& Layer::GetWeights() const {
    std::vector<Vector> weights;
    for (const Perceptron& perceptron : m_perceptrons) {
        weights.push_back(perceptron.GetWeights());
    }

    return weights;
}

const int Layer::GetInputSize() const {
    return m_input_size;
}

std::vector<Perceptron>& Layer::GetPerceptrons() {
    return m_perceptrons;
}

Vector Layer::Forward(const Vector& inputs) {
    assert(inputs.Size() == m_input_size);

    Vector outputs(m_num_perceptrons);
    for (int i = 0; i < m_num_perceptrons; i++) {
        outputs.Set(i, m_perceptrons[i].Forward(inputs));
    }

    return outputs;
}

void Layer::Backward(const Vector& outputs, const Vector& deltas, double learning_rate) {
    assert(outputs.Size() == m_num_perceptrons);

    for (int i = 0; i < m_num_perceptrons; i++) {
        m_perceptrons[i].Backward(outputs, deltas.Get(i), learning_rate);
    }
}