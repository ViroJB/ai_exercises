#pragma once

#include <assert.h>

#include <vector>

#include "../perceptron/perceptron.h"
#include "../vector/vector.h"

class Layer {
   public:
    Layer(int input_size, int num_perceptrons);
    ~Layer();

    const std::vector<Vector>& GetWeights() const;
    const int GetInputSize() const;
    std::vector<Perceptron>& GetPerceptrons(); 

    Vector Forward(const Vector& inputs);
    void Backward(const Vector& outputs, const Vector& deltas, double learning_rate);

   private:
    void InitializePerceptrons();

    // members
    int m_input_size;
    int m_num_perceptrons;
    std::vector<Perceptron> m_perceptrons;
};