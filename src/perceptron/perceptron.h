#pragma once

#include <assert.h>

#include <numeric>

#include "../matrix/matrix.h"
#include "../vector/vector.h"

class Perceptron {
   public:
    Perceptron(int input_size);
    ~Perceptron();

    void SetWeights(const Vector& weights);
    void SetBias(double bias);

    const Vector& GetWeights() const;
    double GetBias() const;
    int GetInputSize() const;

    double Forward(const Vector& inputs);
    void Backward(const Vector& outputs, double delta, double learning_rate);

   private:
    double Activate(double z);

    // members
    int m_input_size;  // number of inputs
    Vector m_weights;  // weights for each input
    double m_bias;     // threshold for the activation function
};