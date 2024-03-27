#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Sigmoid function definition
float sigmoidf(float x)
{
    return 1.0f / (1.0f + expf(-x));
}

// OR-GATE training data
float train[][3] = {
    {0, 0, 0},
    {1, 0, 1},
    {0, 1, 1},
    {1, 1, 1},
};

#define train_count (sizeof(train) / sizeof(train[0]))

// Cost function definition
float cost(float w1, float w2)
{
    float result = 0.0f;

    // Calculate the cost over the training data
    for (size_t i = 0; i < train_count; ++i)
    {
        float x1 = train[i][0];
        float x2 = train[i][1];
        float y = sigmoidf(x1 * w1 + x2 * w2);
        float d = y - train[i][2]; // Difference between predicted and actual output
        result += d * d;           // Square of the difference (MSE)
    }
    result /= train_count; // Average the cost
    return result;
}

// Function to generate random float values
float rand_float(void)
{
    return (float)rand() / (float)RAND_MAX;
}

int main(void)
{
    for (float x = -10.f; x <= 10.f; x += 1.f)
    {
        printf("%f => %f\n", x, sigmoidf(x));
    }

    return 0;

    srand(69); // Seed the random number generator

    // Initialize random weights
    float w1 = rand_float();
    float w2 = rand_float();

    float eps = 1e-3;  // Small value for numerical differentiation
    float rate = 1e-3; // Learning rate

    // Training loop
    for (size_t i = 0; i < 2000; ++i)
    {
        // Calculate current cost and display weights
        float c = cost(w1, w2);
        // printf("w1 = %f, w2 = %f\n", w1, w2);

        // Numerical differentiation to compute gradients
        float dw1 = (cost(w1 + eps, w2) - c) / eps; // Change in cost with respect to w1
        float dw2 = (cost(w1, w2 + eps) - c) / eps; // Change in cost with respect to w2

        // Update weights using gradient descent
        w1 -= rate * dw1;
        w2 -= rate * dw2;
    }

    return 0;
}
