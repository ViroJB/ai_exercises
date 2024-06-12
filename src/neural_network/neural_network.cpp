#include "neural_network.h"

NeuralNetwork::NeuralNetwork(const std::vector<int>& layer_sizes) {
    m_learning_rate = 0.1;

    for (size_t i = 0; i < layer_sizes.size() - 1; i++) {
        m_layers.emplace_back(Layer(layer_sizes[i], layer_sizes[i + 1]));
    }
}

NeuralNetwork::~NeuralNetwork() {
}

Vector NeuralNetwork::Forward(const Vector& input) {
    Vector result = input;
    for (size_t i = 0; i < m_layers.size(); i++) {
        result = m_layers[i].Forward(result);
    }

    return result;
}

void NeuralNetwork::Backward(const Vector& outputs, const Vector& labels) {
    Vector output_errors = CalculateOutputError(outputs, labels);

    Vector deltas = output_errors;
    Vector layer_outputs = outputs;

    for (size_t i = m_layers.size(); i-- > 0;) {
        m_layers[i].Backward(outputs, deltas, m_learning_rate);

        // calculate deltas for the next layer
        if (i > 0) {
            const std::vector<Vector>& weights = m_layers[i].GetWeights();
            Vector deltas_next(m_layers[i].GetInputSize());

            for (size_t j = 0; j < weights.size(); j++) {
                deltas_next = deltas_next + weights[j].ElementwiseProduct(deltas.Get(j));
            }

            deltas = deltas_next;

            layer_outputs = m_layers[i - 1].Forward(layer_outputs);
        }
    }
}

Vector NeuralNetwork::Predict(const Vector& input) {
    return Forward(input);
}

void NeuralNetwork::Train(const std::vector<Vector>& inputs, std::vector<Vector>& labels, int epochs) {
    for (int epoch = 0; epoch < epochs; ++epoch) {
        for (size_t i = 0; i < inputs.size(); ++i) {
            Vector prediction = Predict(inputs[i]);
            Vector error = labels[i] - prediction;

            Backward(prediction, labels[i]);
        }
    }
}

Vector NeuralNetwork::CalculateOutputError(const Vector& outputs, const Vector& labels) {
    Vector errors(outputs.Size());
    for (int i = 0; i < outputs.Size(); i++) {
        errors.Set(i, labels.Get(i) - outputs.Get(i));
    }

    return errors;
}

void NeuralNetwork::SetLearningRate(double learning_rate) {
    m_learning_rate = learning_rate;
}

double NeuralNetwork::GetLearningRate() const {
    return m_learning_rate;
}