#include "gtest/gtest.h"

#include "../src/layer/layer.h"

TEST(LayerTest, Initialization) {
    int input_size = 3;
    int num_perceptrons = 2;
    Layer layer(input_size, num_perceptrons);

    ASSERT_EQ(layer.GetInputSize(), input_size);

    std::vector<Vector> weights = layer.GetWeights();
    int weights_size = layer.GetWeights().size();
    ASSERT_EQ(weights_size, num_perceptrons);

    for (const Vector& weights : layer.GetWeights()) {
        ASSERT_EQ(weights.Size(), input_size);
    }
}

// Test für die Forward-Methode
TEST(LayerTest, Forward) {
    int input_size = 2;
    int num_perceptrons = 2;
    Layer layer(input_size, num_perceptrons);

    // Setze bekannte Gewichte und Bias-Werte für die Perzeptronen
    Vector weights1(input_size);
    weights1.Set(0, 0.5);
    weights1.Set(1, -0.5);
    layer.GetPerceptrons()[0].SetWeights(weights1);
    layer.GetPerceptrons()[0].SetBias(0.0);

    Vector weights2(input_size);
    weights2.Set(0, -0.5);
    weights2.Set(1, 0.5);
    layer.GetPerceptrons()[1].SetWeights(weights2);
    layer.GetPerceptrons()[1].SetBias(0.0);

    Vector input(input_size);
    input.Set(0, 1.0);
    input.Set(1, 0.0);

    Vector output = layer.Forward(input);
    ASSERT_EQ(output.Size(), num_perceptrons);

    double expected_output1 = 1.0 / (1.0 + std::exp(-0.5));
    double expected_output2 = 1.0 / (1.0 + std::exp(0.5));

    ASSERT_NEAR(output.Get(0), expected_output1, 1e-5);
    ASSERT_NEAR(output.Get(1), expected_output2, 1e-5);
}

// Test für die Backward-Methode
TEST(LayerTest, Backward) {
    int input_size = 2;
    int num_perceptrons = 2;
    Layer layer(input_size, num_perceptrons);

    // Setze bekannte Gewichte und Bias-Werte für die Perzeptronen
    Vector weights1(input_size);
    weights1.Set(0, 0.5);
    weights1.Set(1, -0.5);
    layer.GetPerceptrons()[0].SetWeights(weights1);
    layer.GetPerceptrons()[0].SetBias(0.0);

    Vector weights2(input_size);
    weights2.Set(0, -0.5);
    weights2.Set(1, 0.5);
    layer.GetPerceptrons()[1].SetWeights(weights2);
    layer.GetPerceptrons()[1].SetBias(0.0);

    Vector inputs(input_size);
    inputs.Set(0, 1.0);
    inputs.Set(1, 0.0);

    Vector outputs = layer.Forward(inputs);
    Vector deltas(num_perceptrons);
    deltas.Set(0, 0.1);
    deltas.Set(1, 0.2);
    double learning_rate = 0.01;

    layer.Backward(outputs, deltas, learning_rate);

    // Überprüfe die Aktualisierungen der Gewichte und Bias-Werte
    ASSERT_NEAR(layer.GetPerceptrons()[0].GetWeights().Get(0), 0.5 + 0.01 * 0.1 * 1.0, 1e-5);
    ASSERT_NEAR(layer.GetPerceptrons()[0].GetWeights().Get(1), -0.5 + 0.01 * 0.1 * 0.0, 1e-5);
    ASSERT_NEAR(layer.GetPerceptrons()[0].GetBias(), 0.0 + 0.01 * 0.1, 1e-5);

    ASSERT_NEAR(layer.GetPerceptrons()[1].GetWeights().Get(0), -0.5 + 0.01 * 0.2 * 1.0, 1e-5);
    ASSERT_NEAR(layer.GetPerceptrons()[1].GetWeights().Get(1), 0.5 + 0.01 * 0.2 * 0.0, 1e-5);
    ASSERT_NEAR(layer.GetPerceptrons()[1].GetBias(), 0.0 + 0.01 * 0.2, 1e-5);
}