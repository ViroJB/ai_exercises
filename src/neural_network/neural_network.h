#pragma once

#include <vector>

#include "../layer/layer.h"
#include "../perceptron/perceptron.h"
#include "../vector/vector.h"


class NeuralNetwork {
   public:
    NeuralNetwork(const std::vector<int>& layers_sizes);
    ~NeuralNetwork();

    Vector Forward(const Vector& input);
    void Backward(const Vector& outputs, const Vector& deltas);

    Vector Predict(const Vector& input);
    void Train(const std::vector<Vector>& inputs, std::vector<Vector>& labels, int epochs);

    // not sure about this one... maybe it should be in the Layer class or whatever?
    Vector CalculateOutputError(const Vector& outputs, const Vector& labels);

    void SetLearningRate(double learning_rate);
    double GetLearningRate() const;

   private:
    std::vector<Layer> m_layers;
    double m_learning_rate;
};