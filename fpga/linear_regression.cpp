#include "linear_regression.h"
#include <iostream>
using namespace std;


void linear_regression(dtype X[DATA_SIZE][NO_OF_FEATURES], dtype y_pred[DATA_SIZE]) {
#pragma HLS INTERFACE m_axi depth = 80 port = X offset= slave // read data
#pragma HLS INTERFACE m_axi depth = 20 port = y_pred offset=slave// output size
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL

    // Predefined slopes (weights) and intercept from training
    dtype weights[NO_OF_FEATURES]={11.578635,
        -0.128110,
        -0.813338,
        0.951879};

    // Compute predictions
    for (int i = 0; i < DATA_SIZE; i++) {
        y_pred[i] = 0;
        for (int j = 0; j < NO_OF_FEATURES; j++) {
            y_pred[i] += X[i][j] * weights[j];
        }
    }
}
