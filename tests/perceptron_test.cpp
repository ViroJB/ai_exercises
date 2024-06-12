#include "gtest/gtest.h"

#include "../src/perceptron/perceptron.h"
#include "../src/vector/vector.h"

TEST(PerceptronTest, Initialization) {
    int input_size = 3;
    Perceptron p(input_size);

    ASSERT_EQ(p.GetInputSize(), input_size);

    const Vector& weights = p.GetWeights();
    ASSERT_EQ(weights.Size(), input_size);

    for (int i = 0; i < input_size; ++i) {
        ASSERT_GE(weights.Get(i), -0.5);
        ASSERT_LE(weights.Get(i), 0.5);
    }

    ASSERT_EQ(p.GetBias(), 0.0);
}

// Test für die SetWeights- und SetBias-Methoden
TEST(PerceptronTest, SetWeightsAndBias) {
    int input_size = 3;
    Perceptron p(input_size);

    Vector new_weights(input_size);
    new_weights.Set(0, 0.1);
    new_weights.Set(1, 0.2);
    new_weights.Set(2, 0.3);
    p.SetWeights(new_weights);

    double new_bias = 0.5;
    p.SetBias(new_bias);

    const Vector& weights = p.GetWeights();
    for (int i = 0; i < input_size; ++i) {
        ASSERT_EQ(weights.Get(i), new_weights.Get(i));
    }

    ASSERT_EQ(p.GetBias(), new_bias);
}

// Test für die Forward-Methode
TEST(PerceptronTest, Forward) {
    int input_size = 2;
    Perceptron p(input_size);

    Vector weights(input_size);
    weights.Set(0, 0.5);
    weights.Set(1, -0.5);
    p.SetWeights(weights);
    p.SetBias(0.0);

    Vector input(input_size);
    input.Set(0, 1.0);
    input.Set(1, 0.0);

    double output = p.Forward(input);
    double expected_output = 1.0 / (1.0 + std::exp(-0.5)); // Aktivierungsfunktion (Sigmoid) angewendet auf gewichtete Summe
    ASSERT_NEAR(output, expected_output, 1e-5);
}

// Test für die Backward-Methode
TEST(PerceptronTest, Backward) {
    int input_size = 2;
    Perceptron p(input_size);

    Vector weights(input_size);
    weights.Set(0, 0.5);
    weights.Set(1, -0.5);
    p.SetWeights(weights);
    p.SetBias(0.0);

    Vector input(input_size);
    input.Set(0, 1.0);
    input.Set(1, 0.0);

    double delta = 0.1;
    double learning_rate = 0.01;
    p.Backward(input, delta, learning_rate);

    ASSERT_NEAR(p.GetWeights().Get(0), 0.5 + 0.01 * 0.1 * 1.0, 1e-5);
    ASSERT_NEAR(p.GetWeights().Get(1), -0.5 + 0.01 * 0.1 * 0.0, 1e-5);
    ASSERT_NEAR(p.GetBias(), 0.0 + 0.01 * 0.1, 1e-5);
}