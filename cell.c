#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Training data: x, y pairs
float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8}};

#define train_count (sizeof(train) / sizeof(train[0]))

// Function to generate a random float value between 0 and 1
float rand_float(void)
{
    return (float)rand() / (float)RAND_MAX;
}

// Cost function to calculate the Mean Squared Error (MSE)
float cost(float w, float b)
{
    float result = 0.0f;
    // Loop through each training example
    for (size_t i = 0; i < train_count; ++i)
    {
        float x = train[i][0];
        float y = x * w + b;       // Predicted y using linear regression equation
        float d = y - train[i][1]; // Calculate the difference between predicted and actual y
        result += d * d;           // Squared difference
    }
    result /= train_count; // Calculate the average of squared differences
    return result;
}

int main()
{
    srand(time(NULL)); // Seed the random number generator with current time

    // Initialize random values for weight (w) and bias (b)
    float w = rand_float() * 10.0f; // Random weight between 0 and 10
    float b = rand_float() * 5.0f;  // Random bias between 0 and 5

    // float eps = 1e-3;  // Small value for numerical differentiation
    float rate = 1e-3; // Learning rate

    // Print initial cost
    printf("Initial Cost: %f\n", cost(w, b));

    // Training loop
    for (size_t i = 0; i < 2000; ++i)
    {
        // Calculate current cost
        // float c = cost(w, b);

        float dw = 0.0f; // Gradient for weight
        float db = 0.0f; // Gradient for bias

        // Calculate gradients for each training example
        for (size_t j = 0; j < train_count; ++j)
        {
            float x = train[j][0];
            float y = x * w + b;
            float d = y - train[j][1];

            // Accumulate gradients
            dw += d * x; // Gradient for weight
            db += d;     // Gradient for bias
        }

        // Average gradients
        dw /= train_count;
        db /= train_count;

        // Update weights using gradient descent
        w -= rate * dw;
        b -= rate * db;

        // Print current cost and updated weights
        // printf("Iteration %zu - Cost: %f, w: %f, b: %f\n", i + 1, cost(w, b), w, b);
    }

    // Print final values of weight and bias
    // printf("-----------------------------\n");
    // printf("Final Weight (w): %f, Final Bias (b): %f\n", w, b);

    return 0;
}
